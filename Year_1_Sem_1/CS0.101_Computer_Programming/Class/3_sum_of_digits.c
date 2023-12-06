#include <stdio.h>

int main()
{
    int n, sum = 0, i;

    printf("Please enter a number:");
    scanf("%d", &n);

    for (n = n; n != 0;)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }

    printf("Sum of digits: %d\n", sum);

    return 0;
}