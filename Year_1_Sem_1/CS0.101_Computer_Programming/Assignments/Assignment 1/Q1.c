#include <stdio.h>

// Write a program to accept a value in degrees Celsius and to convert it into Fahrenheit

int main()
{
    int celsius, fahrenheit;

    printf("Please enter a value in celsius: ");
    scanf("%d", &celsius);

    fahrenheit = ((celsius * 9) / 5) + 32;

    printf("%d*C is %d*F\n", celsius, fahrenheit);

    return 0;
}