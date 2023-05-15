#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll add(ll x, ll y);

int main()
{
    ll x, y;
    scanf("%lld %lld", &x, &y);
    ll result = add(x, y);

    printf("%lld\n", result);
    return 0;
}