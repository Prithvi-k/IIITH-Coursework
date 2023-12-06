#include <stdio.h>
#define ll long long int

ll get_sum(ll * arr, ll size);

int main()
{
    ll n;
    scanf("%lld", &n);  //input the size of array.

    ll arr[n];
    for(ll i = 0; i < n; i++)scanf("%lld", &arr[i]);    //input n elements of the array.

    ll ans = get_sum(arr, n);   //This should return the sum of numbers in array which are divisible by 3.
    printf("%lld\n", ans);

    return 0;   
}