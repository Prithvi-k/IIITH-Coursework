#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void people(ll n, ll arr[n], ll ans[n]);

int main()
{
    ll n;
    scanf("%Ld", &n);
    ll arr[n], ans[n];
    for (ll i = 0; i < n; i++)
    {
        scanf("%Ld", &arr[i]);
    }
    people(n, arr, ans);
    for (ll i = 0; i < n; i++)
    {
        printf("%Ld ", ans[i]);
    }
    printf("\n");
    return 0;
}