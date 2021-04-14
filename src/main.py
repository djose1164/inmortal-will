import ctypes
# import os

# file_path = os.path.dirname(__file__)
# dir = os.path.dirname(file_path)

file_path = "/home/djose1164/Desktop/Immortal-Will/src/main.so"
add = ctypes.CDLL(file_path)

print(f"From C code: {add.add(50, 11, 50)}")