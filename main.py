import ctypes
import numpy as np
import matplotlib.pyplot as plt
import os
import sys


width = 800
height = 600
max_iter = 100


dll_path = os.path.abspath("libmandelbrot.dll")

if not os.path.exists(dll_path):
    print("ERRO: libmandelbrot.dll não encontrada.")
    print("Compile primeiro usando:")
    print("gcc -shared -o libmandelbrot.dll mandelbrot.c")
    sys.exit(1)


lib = ctypes.CDLL(dll_path)

lib.generate_mandelbrot.argtypes = [
    ctypes.c_int, ctypes.c_int, ctypes.c_int,
    ctypes.c_double, ctypes.c_double,
    ctypes.c_double, ctypes.c_double,
    ctypes.POINTER(ctypes.c_int)
]

lib.generate_mandelbrot.restype = None


output = np.zeros(width * height, dtype=np.int32)


lib.generate_mandelbrot(
    width,
    height,
    max_iter,
    -2.0, 1.0,
    -1.5, 1.5,
    output.ctypes.data_as(ctypes.POINTER(ctypes.c_int))
)


image = output.reshape((height, width))

plt.imshow(image, cmap='hot')
plt.colorbar()
plt.title("Fractal de Mandelbrot (C + Python - Windows)")
plt.show()