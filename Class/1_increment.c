#include <stdio.h>

int main()
{
    int a = 5, b = 5, c, d;

    c = a++; // post-increment
    d = ++b; // pre-increment

    printf("Values of a & b = %d, c = %d, d = %d\n", a, c, d);

    return 0;
}