#include "mandelbrot.h"
#include <math.h>

/*
    Função responsável por calcular o fractal de Mandelbrot.

    Parâmetros:
    - width, height: dimensões da imagem
    - max_iter: número máximo de iterações
    - xmin, xmax, ymin, ymax: limites do plano complexo
    - output: ponteiro para vetor de saída (imagem linearizada)
*/

EXPORT void generate_mandelbrot(
    int width,
    int height,
    int max_iter,
    double xmin,
    double xmax,
    double ymin,
    double ymax,
    int *output
) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            double real = xmin + (x / (double)width) * (xmax - xmin);
            double imag = ymin + (y / (double)height) * (ymax - ymin);

            double z_real = 0.0;
            double z_imag = 0.0;

            int iter = 0;

            while (z_real * z_real + z_imag * z_imag <= 4.0 && iter < max_iter) {
                double temp = z_real * z_real - z_imag * z_imag + real;
                z_imag = 2.0 * z_real * z_imag + imag;
                z_real = temp;
                iter++;
            }

            output[y * width + x] = iter;
        }
    }
}