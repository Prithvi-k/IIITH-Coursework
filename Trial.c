#include <stdio.h>
#include <unistd.h>

/*

Write a program to print the following pattern:

*
**
***
****
*****
******
******
*****
****
***
**
*

*/
int main()
{
    int a, a1, a2, i, j;

    printf("Please enter a number: ");
    scanf("%d", &a);

    a1 = a;
    a2 = a;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < i; i++)
        {
            printf("Chirag OP");
        }
        printf("\n");
    }

    for (int i = a - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; i++)
        {
            printf("Chirag OP");
            sleep(5);
        }
        printf("\n");
    }

    return 0;
}