#include <stdio.h>

int main()
{
    int a = 5, b = 6, temp;

    printf("Before swap a = %d and b = %d\n", a, b);

    temp = a;
    a = b;
    b = temp;

    printf("After swap a = %d and b = %d\n", a, b);

    return 0;
}