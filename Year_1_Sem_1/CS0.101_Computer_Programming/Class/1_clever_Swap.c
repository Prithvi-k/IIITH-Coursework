#include <stdio.h>

int main()
{
    int a = 5, b = 6;

    printf("Before swap a = %d and b = %d\n", a, b);

    a = a + b - (b = a); // by operator precedence, 'b=a' is evaluated first, hence a is assigned value equal to b

    printf("After swap a = %d and b = %d\n", a, b);

    return 0;
}