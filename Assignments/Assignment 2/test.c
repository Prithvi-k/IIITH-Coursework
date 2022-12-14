#include <stdio.h>

int main()
{
    long double x = 2, y = 3;

    printf("%0.100Lf", x / y);
}