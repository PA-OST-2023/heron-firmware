Import("env")

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
        Path("UI/DisplayLVGL_NXP/generated").resolve(),
        Path("UI/DisplayLVGL_NXP/custom").resolve()
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


copy_directory()

# env.AddPreAction("buildprog", copy_directory())
