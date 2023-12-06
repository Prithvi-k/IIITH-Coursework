#include <stdio.h>
#define ll long long int

ll * get_address_smallest(ll * arr, ll size);

int main()
{
    ll n;
    scanf("%lld", &n); //input size of the array

    ll arr[n];

    for(ll i = 0; i < n; i++)scanf("%lld", &arr[i]); //input n elements of the array.

    printf("%lld\n", *(get_address_smallest(arr, n))); //dereference the address returned and print the element corresponding to it.

    return 0;
}