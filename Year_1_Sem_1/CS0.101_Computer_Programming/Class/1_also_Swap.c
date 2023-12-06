#include <stdio.h>

int main()
{

    int a = 5, b = 6;

    printf("Before swap a = %d and b = %d\n", a, b);

    a = a + b;
    b = a - b; // b = (a + b) - b = a
    a = a - b; // a = (a + b) - a = b

    printf("After swap a = %d and b = %d\n", a, b);

    return 0;
}