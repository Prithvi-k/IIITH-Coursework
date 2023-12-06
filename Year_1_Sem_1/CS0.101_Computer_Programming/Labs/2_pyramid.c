#include <stdio.h>

int main()
{
    int rows, num = 1;

    printf("Please enter number of rows required: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j < (rows - i); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("%d ", num++);
        }
        printf("\n");
    }
    /* for (int i = 1; i <= rows; i++)
    {
        for (int j = (rows - i); j >= 0; j--)
        {
            for (int m = 0; m < j; m++)
            {
                printf(" ");
            }

            for (int k = 1; k <= i; k++)
            {
                printf("%d ", num);
                num++;
            }
            printf("\n");
        }
    } */

    return 0;
}