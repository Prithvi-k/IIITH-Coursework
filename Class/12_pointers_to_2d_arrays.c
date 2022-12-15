#include <stdio.h>

int main()
{
    int arr[2][3] = {{22, 32, 34}, {23, 21, 25}};

    // both are same
    printf("arr : %p\n", arr);
    printf("*arr : %p\n", *arr);

    for (int i = 0; i < 2; i++)
    {
        // both are same
        printf("i = %d\n", i);
        printf("arr + i: %p\n", arr + i);
        printf("*(arr + i): %p\n", (*(arr + i)));

        for (int j = 0; j < 3; j++)
        {
            printf("j = %d\n", j);
            printf("(arr + i) + j: %p\n", ((arr + i) + j));
            printf("*(arr + i) + j: %p\n", (*(arr + i) + j));
            printf("Value = %d \n\n", *(*(arr + i) + j));
        }
        printf("\n");
    }

    return 0;
}