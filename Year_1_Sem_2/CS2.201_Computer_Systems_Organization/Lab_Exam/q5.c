#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void sort(ll n, ll *arr1, ll *sorted_arr);

int main()
{
    ll n;
    scanf("%lld", &n);
    ll *arr = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    ll *result = (ll *)calloc(n, sizeof(ll));
    sort(n, arr, result);
    for (ll i = 0; i < n; i++)
    {
        printf("%lld ", result[i]);
    }
    printf("\n");
    return 0;
}