#include <stdio.h>
#define ll long long int

ll divFunc(ll m, ll n);

int main()
{
    ll n, m;
    scanf("%lld %lld", &m, &n); // scan for m and n
    ll ans = divFunc(m, n);     // arr[0] must contain quotient, arr[1] must contain the remainder
    printf("%lld\n", ans);
    return 0;
}
