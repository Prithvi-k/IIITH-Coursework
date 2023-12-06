#include <stdio.h>

/*

If a n-digit number is input through the keyboard, write a program to reverse the number.

*/

int main()
{
    int num, num_rev = 0, rem, count = 0, i = 0;
    printf("Please enter a n-digit number: ");
    scanf("%d", &num);

    int num_copy = num;

    while (num_copy != 0)
    {
        num_copy = num_copy / 10;
        count++;
    }

    while (i < count)
    {
        rem = num % 10;
        num_rev = (num_rev * 10) + rem;
        num = num / 10;
        i++;
    }

    printf("Reversed number is: %d\n", num_rev);

    return 0;
}