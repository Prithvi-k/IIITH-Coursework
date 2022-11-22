#include <stdio.h>

/*

Write a program to print the following pattern:
*******
******
*****
****
***
**
*

*/
int main()
{
    int i = 6;

    while (i-- > 0)
    {
        int a = 0;
        char str[] = "*";
        for (a = 0; a <= i; a++)
        {
            printf("%s", str);
        }
        printf("\n");
    }

    return 0;
}