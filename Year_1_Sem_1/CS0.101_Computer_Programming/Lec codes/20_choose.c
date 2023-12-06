#include "stdio.h"

int choose(int n, int k)
{
    return k == 0 ? 1 : choose(n, k - 1) * (n - k + 1) / k;
}

int choose_by_pascal(int n, int k)
{

    return (n == k || k == 0) ? 1 : choose_by_pascal(n - 1, k) + choose_by_pascal(n - 1, k - 1);
}

int main()
{

    int n = 6;
    int k = 3;
    printf("%d\n", choose_by_pascal(n, k));

    return 0;
}