#include <stdio.h>

int main()
{
    int i = 10;
    int j = 10;

    while (i--)
    {
        printf("%d ", i);
    }

    printf("\n");

    while (--j)
    {
        printf("%d ", j);
    }

    printf("\n");

    /*
        while loop stops at '0'
        while loops don't require {}, just conventional & helps in nested whiles
    */

    return 0;
}