#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Complex_Number
{
    int real;
    int imaginary;
} Complex_Number;

Complex_Number add(Complex_Number a, Complex_Number b)
{
    Complex_Number c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
}

Complex_Number subtract(Complex_Number a, Complex_Number b)
{
    Complex_Number c;
    c.real = a.real - b.real;
    c.imaginary = a.imaginary - b.imaginary;
    return c;
}

Complex_Number multiply(Complex_Number a, Complex_Number b)
{
    Complex_Number c;
    c.real = a.real * b.real - a.imaginary * b.imaginary;
    c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return c;
}

int main()
{
    Complex_Number z1, z2;
    int option, flag = 0;

    while (flag != 1)
    {

        printf("Select operation:\n");
        printf("1 for addition\n");
        printf("2 for subtraction\n");
        printf("3 for multiplication\n");
        printf("4 for ending program\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Complex_Number addition_result;
            printf("Please enter a complex number (x + yi):\n");
            printf("z1: ");
            scanf("%d + %di", &z1.real, &z1.imaginary);

            printf("z2: ");
            scanf("%d + %di", &z2.real, &z2.imaginary);
            addition_result = add(z1, z2);
            printf("z1 + z2 = %d +  %di\n\n", addition_result.real, addition_result.imaginary);
            break;

        case 2:
            Complex_Number subtraction_result;
            printf("Please enter a complex number (x + yi):\n");
            printf("z1: ");
            scanf("%d + %di", &z1.real, &z1.imaginary);

            printf("z2: ");
            scanf("%d + %di", &z2.real, &z2.imaginary);
            subtraction_result = subtract(z1, z2);
            printf("z1 - z2 = %d + %di\n\n", subtraction_result.real, subtraction_result.imaginary);
            break;

        case 3:
            Complex_Number multiplication_result;
            printf("Please enter a complex number (x + yi):\n");
            printf("z1: ");
            scanf("%d + %di", &z1.real, &z1.imaginary);

            printf("z2: ");
            scanf("%d + %di", &z2.real, &z2.imaginary);
            multiplication_result = multiply(z1, z2);
            printf("z1 x z2 = %d + %di\n\n", multiplication_result.real, multiplication_result.imaginary);
            break;

        case 4:
            flag = 1;
            break;

        default:
            break;
        }
    }

    return 0;
}