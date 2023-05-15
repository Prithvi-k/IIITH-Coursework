#include <stdio.h>
#include <stdlib.h>

#define ll long long int

// ll rem(ll n);
ll alt_sum(ll *arr, ll n);

int main()
{
    ll n;
    scanf("%Ld", &n);
    ll *arr = (ll *)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++)
    {
        scanf("%Ld", &arr[i]);
    }

    ll ans = alt_sum(arr, n);
    printf("%Ld", ans);
    return 0;
}