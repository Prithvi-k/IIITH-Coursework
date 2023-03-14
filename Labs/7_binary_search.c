#include <stdio.h>

// Square root using binary search

int main()
{
    int n;
    scanf("%d", &n);
    int l = 0, r = n, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if ((mid * mid) == n) {
            ans = mid;
            break;
        } else if ((mid * mid) < n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}