Import("env")

import os
import shutil
import stat
from pathlib import Path

def rmtree(top):
    for root, dirs, files in os.walk(top, topdown=False):
        for name in files:
            filename = os.path.join(root, name)
            os.chmod(filename, stat.S_IWUSR)
            os.remove(filename)
        for name in dirs:
            if os.name == 'nt':     # check if windows
                os.system('rmdir /S /Q "{}"'.format(name))
            os.rmdir(os.path.join(root, name))
    os.rmdir(top) 


def on_rm_error(func, path, exc_info):
    # path contains the path of the file that couldn't be removed
    # let's just assume that it's read-only and unlink it.
    os.chmod(path, stat.S_IWRITE)
    os.unlink(path)


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
        # Check if source directory exists
        if not os.path.exists(src):
            print(f"Source directory {src} does not exist. Skipping.")
            return

        # If destination directory exists, remove it first
        if os.path.exists(dst):
            # rmtree(dst)
            shutil.rmtree(dst, onerror=on_rm_error)

        # Copy the entire directory recursively
        shutil.copytree(src, dst)
        print(f"Copied {src} to {dst}.")

    print("Copying directories")


copy_directory()


# env.AddPreAction("buildprog", copy_directory())
