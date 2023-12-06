#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
Given a positive integer N, return an array of integers with all the integers from 1 toN. But for multiples of 3 the array should have -1 instead of the number, for multiples of 5 the array should have -2 instead of the number, and for multiples of both 3 and 5 the array should have -3 instead of the number.
*/

typedef long long ll;
void compute(ll *array, int n);

int main()
{
    int n;
    scanf("%d", &n);
    ll *arr = (ll *)malloc(n * sizeof(ll));
    assert(arr != NULL);
    compute(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%Ld ", arr[i]);
    }
    printf("\n");

    return 0;
}