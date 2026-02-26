all:
	gcc -shared -o libmandelbrot.dll mandelbrot.c

run: all
	python main.py