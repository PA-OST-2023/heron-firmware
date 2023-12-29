# Import("env")

import os
import shutil
import stat
from pathlib import Path
import subprocess

def unset_readonly(path):
    dirPaths = []
    if os.name == 'nt':     # check if windows
        dirPaths.append(path)
        for root, dirs, files in os.walk(path, topdown=False):
            dirPaths.append(root)
            for name in files:
                filename = os.path.join(root, name)
                os.chmod(filename, stat.S_IWUSR)
            for name in dirs:
                dirPaths.append(os.path.join(root, name))
        for dirPath in dirPaths:
            subprocess.run(["powershell", "-Command", f"(Get-Item -Path '{dirPath}').Attributes = (Get-Item -Path '{dirPath}').Attributes -band -bnot [System.IO.FileAttributes]::ReadOnly"])

def copy_directory():
    src_dirs = [
        Path("UI/generated").resolve(),
        Path("UI/custom").resolve(),
    ]

    dst_dirs = [
        Path("src/Gui/generated").resolve(),
        Path("src/Gui/custom").resolve()
    ]

    for src, dst in zip(src_dirs, dst_dirs):
        if not os.path.exists(src):     # Check if source directory exists
            print(f"Source directory {src} does not exist. Skipping.")
            return
        if os.path.exists(dst):         # If destination directory exists, remove it first
            unset_readonly(dst)
            shutil.rmtree(dst)
        shutil.copytree(src, dst)       # Copy the entire directory recursively
        unset_readonly(dst)
    print("Prebuild-Script: Copied UI files")

def modify_flash_constants(dir):
    fontFiles = os.listdir(Path(dir).resolve() / "guider_fonts")    # get all files in font directory
    fontFiles = [file for file in fontFiles if file.endswith(".c")]
    for font in fontFiles:
        with open(Path(dir).resolve() / "guider_fonts" / font, "r", encoding="utf8") as f:
            lines = f.readlines()

        # search for the line which starts with "#ifndef LV_FONT_" and add #include <Arduino.h> before it
        for i, line in enumerate(lines):
            if line.startswith("#ifndef LV_FONT_"):
                lines.insert(i, "#include <Arduino.h>\n\n")
                break

        # search for the line which ends with glyph_bitmap[] and add PROGMEM after it
        for i, line in enumerate(lines):
            if line.endswith("glyph_bitmap[] = {\n"):
                lines.remove(line)
                lines.insert(i, "static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] PROGMEM = {\n")
                break

        # search for the line which ends with glyph_dsc[] and add PROGMEM after it
        for i, line in enumerate(lines):
            if line.endswith("glyph_dsc[] = {\n"):
                lines.remove(line)
                lines.insert(i, "static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] PROGMEM = {\n")
                break

        with open(Path(dir).resolve() / "guider_fonts" / font, "w", encoding="utf8") as f:
            f.writelines(lines)

    imageFiles = os.listdir(Path(dir).resolve() / "images")    # get all files in image directory
    imageFiles = [file for file in imageFiles if file.endswith(".c")]
    for image in imageFiles:
        with open(Path(dir).resolve() / "images" / image, "r", encoding="utf8") as f:
            lines = f.readlines()

        # search for the line which starts with "#ifndef LV_ATTRIBUTE_MEM_ALIGN" and add #include <Arduino.h> before it
        for i, line in enumerate(lines):
            if line.startswith("#ifndef LV_ATTRIBUTE_MEM_ALIGN"):
                lines.insert(i, "#include <Arduino.h>\n\n")
                break

        # search for the line which ends with image_data[] and add PROGMEM after it
        for i, line in enumerate(lines):
            if line.endswith("[] = {\n"):
                lineContent = line.split("=")[0]
                lines.remove(line)
                lines.insert(i, lineContent + "PROGMEM = {\n")
                break

        with open(Path(dir).resolve() / "images" / image, "w", encoding="utf8") as f:
            f.writelines(lines)

def addFlashmemToScreens(dir):
    screenFiles = os.listdir(Path(dir).resolve())    # get all files in font directory
    screenFiles = [file for file in screenFiles if file.startswith("setup_scr")]
    for screen in screenFiles:
        with open(Path(dir).resolve() / screen, "r", encoding="utf8") as f:
            lines = f.readlines()

        # search for the line which starts with [#include "custom.h"] and add #include <Arduino.h> before it
        for i, line in enumerate(lines):
            if line.startswith('#include "custom.h"'):
                lines.insert(i + 1, "#include <pgmspace.h>\n")
                break

        # search for the line which starts with "void" and add "FLASHMEM" before it
        for i, line in enumerate(lines):
            if line.startswith('void'):
                lines.insert(i, "FLASHMEM ")
                break

        # search for the line which starts with "static lv_color_t" and add "DMAMEM" before it -> TODO: Check if EXTMEM is needed here
        for i, line in enumerate(lines):
            if line.strip().startswith('static lv_color_t'):
                spaces = line.split("static")[0]
                lineStripped = line.strip()
                lines.remove(line)
                lines.insert(i, f"{spaces}DMAMEM {lineStripped}\n")
                break

        with open(Path(dir).resolve() / screen, "w", encoding="utf8") as f:
            f.writelines(lines)


def addMissingWIdgetReferences(dir):
    screenFiles = os.listdir(Path(dir).resolve())    # get all files in font directory
    screenFiles = [file for file in screenFiles if file.startswith("setup_scr")]

    widgetPointerTypes = ["lv_meter_indicator_t"]
    additionalWidgetsPointers = []
    for screen in screenFiles:
        with open(Path(dir).resolve() / screen, "r", encoding="utf8") as f:
            lines = f.readlines()

        # search for the "lv_meter_indicator_t"
        for i, line in enumerate(lines):
            if any(line.strip().startswith(widgetType) for widgetType in widgetPointerTypes):
                for widgetType in widgetPointerTypes:
                    if line.strip().startswith(f"{widgetType} *"):
                        widgetName = line.split("*")[1].split(";")[0].strip()
                        lines.remove(line)
                        additionalWidgetsPointers.append((widgetType, widgetName))

        # add ui reference to all widgets
        for i, line in enumerate(lines):
            for widgetType, widgetName in additionalWidgetsPointers:        # search for each widget anywehere in the file name and place "ui->" before it
                if widgetName in line:
                    lines[i] = line.replace(widgetName, f"ui->{widgetName}")
        
        with open(Path(dir).resolve() / screen, "w", encoding="utf8") as f:
            f.writelines(lines)

    # Adding missing widget references to gui_guider.h
    with open(Path(dir).resolve() / "gui_guider.h", "r", encoding="utf8") as f:
        lines = f.readlines()
        for i, line in enumerate(lines):
            if line.strip().startswith("}lv_ui;"):  # serach for end of struct
                for w in additionalWidgetsPointers:
                    lines.insert(i, f"\t{w[0]} *{w[1]};\n")
                break
    with open(Path(dir).resolve() / "gui_guider.h", "w", encoding="utf8") as f:
        f.writelines(lines)
        

def redefine_as_cpp(c_file):
    cpp_file = c_file.with_suffix(".cpp")
    os.rename(c_file, cpp_file)


copy_directory()
modify_flash_constants(Path("src/Gui/generated").resolve())
addFlashmemToScreens(Path("src/Gui/generated").resolve())
addMissingWIdgetReferences(Path("src/Gui/generated").resolve())
redefine_as_cpp(Path("src/Gui/generated/events_init.c").resolve())

# env.AddPreAction("buildprog", copy_directory())
