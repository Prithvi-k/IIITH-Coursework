#include <stdio.h>

int print_array(int a, int b, int array[][b]);

int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    print_array(m, n, arr);
    return 0;
}

int print_array(int a, int b, int array[][b])
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}