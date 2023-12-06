#include <stdio.h>
#define ll long long int


ll calculate(ll a, ll x, ll b, ll y);

int main()
{
    ll a, x, b, y;
    scanf("%lld %lld %lld %lld", &a, &x ,&b ,&y);

    //Ans should hold the value of a.2^x + b.2^y
    ll ans = calculate(a, x, b ,y);

    printf("%lld\n", ans);

    return 0;
}
