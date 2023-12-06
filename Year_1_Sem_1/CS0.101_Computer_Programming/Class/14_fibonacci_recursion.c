#include <stdio.h>

int fibonnacci(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    else
    {
        return (fibonnacci(x - 1) + fibonnacci(x - 2));
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        printf("%d ", fibonnacci(i));
    }

    return 0;
}