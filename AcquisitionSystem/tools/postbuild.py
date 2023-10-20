Import("env")

def open_console(source, target, env):
    print("open console")


env.AddPostAction("upload", open_console)
