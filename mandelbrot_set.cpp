#include <iostream>
#include <complex>
#include <fstream>

using namespace std;

int mandelbrotSet(const complex<double>& c, int maxIterations)
{
    complex<double> z = 0;
    int iterations = 0;

    while (abs(z) <= 2 && iterations < maxIterations)
    {
        z = z * z + c;
        iterations++;
    }

    return iterations;
}

int main()
{
    const int width = 80*1.5*3;
    const int height = 40*2*3;
    const double xmin = -2.0;
    const double xmax = 1.0;
    const double ymin = -1.5;
    const double ymax = 1.5;
    ofstream file("out.txt");
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            double x = xmin + (xmax - xmin) * col / (width - 1);
            double y = ymin + (ymax - ymin) * row / (height - 1);
            complex<double> c(x, y);

            int iterations = mandelbrotSet(c, 1000);

            if (iterations == 1000)
            {
                file << '*';
            }
            else
            {
                file << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}