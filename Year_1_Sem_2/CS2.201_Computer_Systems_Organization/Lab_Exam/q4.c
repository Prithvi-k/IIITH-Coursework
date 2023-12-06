#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll gcd(ll a, ll b);
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll g = gcd(n, m);
    printf("%lld\n", g);
    return 0;
}