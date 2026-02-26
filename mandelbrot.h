#ifndef MANDELBROT_H
#define MANDELBROT_H

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

EXPORT void generate_mandelbrot(
    int width,
    int height,
    int max_iter,
    double xmin,
    double xmax,
    double ymin,
    double ymax,
    int *output
);

#endif