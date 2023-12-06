#include <stdio.h>

/*

If a four digit number is input through the keyboard, write a program to reverse the number.

*/

int main()
{
    int num, num_rev = 0, rem, i = 0;
    printf("Please enter a 4-digit number: ");
    scanf("%d", &num);

    while (i < 4)
    {
        rem = num % 10;
        num_rev = (num_rev * 10) + rem;
        num = num / 10;
        i++;
    }

    printf("Reversed number is: %d\n", num_rev);

    return 0;
}