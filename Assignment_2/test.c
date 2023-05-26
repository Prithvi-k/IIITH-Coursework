#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define int ll

ll func(ll *arr, ll x);

int main()
{
    int x;
    scanf("%lld", &x);

    int *a = (int *)malloc(sizeof(int) * x);
    for (int i = 0; i < x; i++)
    {
        scanf("%lld", &a[i]);
    }
    int result = func(a, x);
    for (int i = 0; i < x; i++)
    {
        printf("%lld ", a[i]);
    }
    
    return 0;
}