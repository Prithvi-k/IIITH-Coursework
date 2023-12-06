#include <stdio.h>

// defining a new function to find max element of array
int find_max_array(int len, int a[]) // needs to be arr[] to specify array
{
    int max = 0;

    for (int j = 0; j < len; j++)
    {
        if (a[j] > max)
        {
            max = a[j];
        }
    }
    return max;
}

int main()
{
    int n;
    printf("Please enter length of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = find_max_array(n, arr); // do not need [] for array
    printf("\n%d\n", ans);
    return 0;
}