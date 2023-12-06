#include <stdio.h>
#define ll long long int

void divide(ll m, ll n, ll* arr);


int main()
{
    ll n, m;
    scanf("%lld %lld", &m, &n);     // scan for m and n
    ll arr[2] = {0};
    divide(m, n, arr);              // arr[0] must contain quotient, arr[1] must contain the remainder
    printf("%lld %lld\n", arr[0], arr[1]);
    return 0;   
}



