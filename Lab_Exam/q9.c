#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll first_missing_positive(ll n, ll *arr);

int main()
{
    ll n;
    scanf("%lld", &n);
    ll *arr = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    printf("%lld\n", first_missing_positive(n, arr));
    // first_missing_positive(n, arr);
    // for (ll i = 0; i < n; i++)
    // {
    //     printf("%lld ", arr[i]);
    // }

    return 0;
}