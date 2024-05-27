import os
import shutil
import subprocess

subprocess.run(['git', 'submodule', 'init'])
subprocess.run(['git', 'submodule', 'update'])

shutil.copy2('./libs/imgui/misc/cpp/imgui_stdlib.cpp', './libs/imgui')
shutil.copy2('./libs/imgui/misc/cpp/imgui_stdlib.h', './libs/imgui')

if os.name == 'nt':
  subprocess.run(['build.bat'])
else:
  subprocess.run(['./build.sh'], shell=True)

