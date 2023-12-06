#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void bubble_sort(ll *arr, ll n);

int main()
{
    ll n;
    scanf("%lld", &n);
    ll *arr = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    bubble_sort(arr, n);
    for (ll i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}