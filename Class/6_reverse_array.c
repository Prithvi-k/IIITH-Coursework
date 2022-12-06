#include <stdio.h>

int main()
{
    int arr[5] = {10, 6, 8, 4, 1}, temp;

    for (int i = 0; i < (5 / 2); i++)
    {
        temp = arr[i];
        arr[i] = arr[4 - i];
        arr[4 - i] = temp;
    }

    for (int j = 0; j < (sizeof(arr) / sizeof(arr[0])); j++)
    {
        printf("%d\n", arr[j]);
    }

    return 0;

    /* printf("Size of array = %lu\n", sizeof(arr));
    printf("Size of arr[0] = %lu\n", sizeof(arr[0])); */
}