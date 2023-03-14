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

    int sum = 0, start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        end = i;

        while (sum > req_sum)
        {
            sum -= A[start];
            start++;
        }

        if (sum == req_sum)
        {
            printf("Subarray found from index %d to %d\n", start, end);
            return 0;
        }
    }

    return 0;
}