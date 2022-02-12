import os
import glob

files = glob.glob("./*")
for file in files:
    
    _, ext = os.path.splitext(file)
    #print(file, ext)
    
    if (ext == ".exe"):
        print(f"delete {file}")
        os.remove(file)


