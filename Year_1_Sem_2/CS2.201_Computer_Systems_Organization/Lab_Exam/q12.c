#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll possible(ll number, ll height_diff, ll *arr);

int main()
{
    ll number, height_diff;
    scanf("%lld %lld", &number, &height_diff);
    ll *heights = (ll *)malloc(sizeof(ll) * (number * 2));
    for (ll i = 0; i < (number * 2); i++)
    {
        scanf("%lld", &heights[i]);
    }
    (possible(number, height_diff, heights)) ? printf("YES\n") : printf("NO\n");
    // possible(number, height_diff, heights);
    // printf("%Ld\n", possible(number, height_diff, heights));
    // for (ll i = 0; i < (number * 2); i++)
    // {
    //     printf("%lld ", heights[i]);
    // }
    // printf("\n");
    return 0;
}