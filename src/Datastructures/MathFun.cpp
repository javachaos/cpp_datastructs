#include <cmath>

long double calculatePI(unsigned long int precision)
{
    long double pi = 0.0;
    long double sign = 1.0;
    for (unsigned long int i = 1; i < precision; i++)
    {
        if (i % 2 != 0)
        {
            pi += sign * 4.0 / (long double) i;
            sign *= -1;
        }
    }
    return pi;
}