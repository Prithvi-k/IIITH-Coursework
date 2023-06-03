#include <stdio.h>
#define ll long long int

ll special_op(ll, ll , ll, ll, ll, ll, ll, ll y);

int main()
{
    ll arr[8];
    for(int i = 0; i < 8; i++)
    {
        scanf("%lld", &arr[i]);   
    }

    ll z = special_op(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
    
    printf("%lld\n",z);

    return 0;
}