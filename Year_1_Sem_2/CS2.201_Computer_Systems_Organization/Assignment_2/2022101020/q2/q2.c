#include <stdio.h>
 
#define int long long int

int binarySearch(int* arr, int l, int r, int x);
 
signed main()
{
    int n;
    scanf("%lld",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    int x;
    scanf("%lld",&x);
    int result = binarySearch(arr, 0, n-1, x);
    printf("%lld\n",result);
    return 0;
}