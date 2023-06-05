#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void compute_result(ll n, ll *arr);

int main()
{
    ll n;
    scanf("%lld", &n);
    ll *arr = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    compute_result(n, arr);
    for (ll i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}