#include <stdio.h>

void findNearest(long long int *array, long long int *ans, long long int n);

int main()
{
    long long int n; 
    scanf("%lld", &n);

    long long int array[n];
    long long int ans[n];

    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", &(array[i]));
    }

    findNearest(array, ans, n);

    for (long long int i = 0; i < n; i++)
    {
        printf("%lld ", ans[i]);
    }

    printf("\n");

    return 0;
}