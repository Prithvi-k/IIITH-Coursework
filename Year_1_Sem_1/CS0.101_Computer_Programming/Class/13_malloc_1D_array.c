#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(10 * (sizeof(int)));

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", (arr + i));
        // scanning to ADDRESS of ith element
    }

    // arr[j] = *(arr + j)
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", arr[j]);
    }

    printf("\n");

    for (int k = 0; k < 10; k++)
    {
        printf("%d ", *(arr + k));
    }

    printf("\n");
    return 0;
}