#include <stdio.h>

/*
A year is input through the keyboard.
Write a program to determine whether or not the year is a leap year.\
*/

int main()
{
    int year;
    printf("Enter a year:%d", year);
    scanf("%d", &year);
    printf("\n");
    if (year % 4 == 0)
    {
        printf("%d is a leap year.\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }
    return 0;
}