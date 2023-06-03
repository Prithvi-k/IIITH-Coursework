#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll compute_result(ll n, ll *array);

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll *arr = (ll *)malloc(sizeof(ll) * (n * m));
    for (ll i = 0; i < n * m; i++)
    {
        scanf("%lld", &arr[i]);
    }
    ll result = compute_result(n * m, arr);
    printf("%lld\n", result);
    return 0;
}