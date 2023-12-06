#include <stdio.h>

int choose(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return (choose(a, b - 1) * (a - b + 1) / b);
    }
}

int choose_by_pascal(int n, int k)
{
    if (k == 0 || n == k)
    {
        return 1;
    }
    else
    {
        return choose_by_pascal(n - 1, k - 1) + choose_by_pascal(n - 1, k);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    printf("Choose by recursion = %d\n", choose(n, k));
    printf("Choose by Pascal's = %d\n", choose_by_pascal(n, k));
    return 0;
}