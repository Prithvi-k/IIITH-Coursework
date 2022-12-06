#include <stdio.h>

/*

Given an array, find a sub array such that sum of all elements must equal an input.

 */

int main()
{
    int n, req_sum;

    printf("Enter length of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");

    int A[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the sum required: ");
    scanf("%d", &req_sum);

    int length_of_subarray;

    return 0;
}