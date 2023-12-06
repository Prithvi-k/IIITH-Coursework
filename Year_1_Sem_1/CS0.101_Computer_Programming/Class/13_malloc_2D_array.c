#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r = 4, c = 3, count = 0;

    int *arr[r]; // array of pointers (considered to be first column of 2D array)

    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
        // allocating pointer to array to each element of 1st column array
    }

    for (int j = 0; j < r; j++)
    {
        for (int k = 0; k < c; k++)
        {
            arr[j][k] = ++count;
        }
    }

    for (int p = 0; p < r; p++)
    {
        for (int q = 0; q < c; q++)
        {
            printf("%d ", arr[p][q]);
        }
        printf("\n");
    }

    return 0;
}