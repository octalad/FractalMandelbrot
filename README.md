Fizemos o trabalho baseado na fractal de mandelbrot, onde utilizamos a linguagem C no arquivo mandelbrot.c para gerar a fractal e a linguagem Python no arquivo main.py para fazer a interface!

# Integrantes

Octavio Nickel Ladeira
Julia Brenda Souza da Rosa

# Compilação

gcc -shared -o libmandelbrot.dll mandelbrot.c

# Execução

python main.py

# Dependências

- gcc
- python3
- numpy
- matplotlib

Instalar dependências Python:
pip install numpy matplotlibsudo apt update
sudo apt install gcc make python3 python3-pip -y
pip3 install numpy matplotlib
