#include <stdio.h>

/*

Given an input of 6 integers, display the second largest number.

*/

int main()
{
    int a, i, req, max;
    printf("Enter 6 numbers: ");
    scanf("%d", &max);

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a);
        if (a > max)
        {
            req = max;
            max = a;
        }
        else
        {
            if (a > req)
            {
                req = a;
            }
        }
    }

    printf("Second largest = %d\n", req);

    return 0;
}