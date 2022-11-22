#include <stdio.h>

int main()
{
    int a, i, sum;

    printf("Please enter a number: ");
    scanf("%d", &a);

    for (i = 1; i <= a; i++)
    {
        sum = sum + i;
    }

    printf("%d\n", sum);

    return 0;
}