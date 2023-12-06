#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void selective_sort(ll n, ll *arr);

int main()
{
    ll n;
    scanf("%lld", &n);
    ll *arr = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    selective_sort(n, arr);
    for (ll i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}