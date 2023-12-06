#include <stdio.h>

int test(int x);

int main()
{
    int n;
    scanf("%d", &n);
    int z = test(n);
    printf("%d\n", z);
    return 0;
}