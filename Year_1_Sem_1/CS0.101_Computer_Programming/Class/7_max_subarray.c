#include <stdio.h>

int main()
{
    int n, length_of_subarray, max = 0;

    printf("Enter length of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Length of subarray: ");
    scanf("%d", &length_of_subarray);

    /* for (int j = 0; j <= (n - (length_of_subarray)); j++)
    {
        int sum = 0;

        for (int k = j; k < (j + length_of_subarray); k++)
        {
            sum += arr[k];
        }

        if (sum >= max)
        {
            max = sum;
        }
    } */

    /*

    O(n) silution --> 'Sliding Window' method

     */

    int sum_2 = 0;

    for (int i = 0; i < length_of_subarray; i++)
    {
        sum_2 += arr[i];
    }

    int alt_sum = sum_2;

    for (int l = length_of_subarray; l < n; l++)
    {
        alt_sum += arr[l] - arr[l - length_of_subarray];

        if (alt_sum > sum_2)
        {
            sum_2 = alt_sum;
        }
    }

    // printf("Max = %d\n", max);
    printf("Max = %d\n", sum_2);
    

    return 0;
}