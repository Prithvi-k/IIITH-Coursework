#include <stdio.h>

int main()
{
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}};

    int(*ptr)[4]; // pointer to array takes index 4 because each array contains 4 elements

    ptr = arr; // pointer points to first 1D array

    printf("%p %p %p\n", ptr, ptr + 1, ptr + 2);
    printf("%p %p %p\n", *ptr, *(ptr + 1), *(ptr + 2));
    // ptr == *ptr -> pointer to first element of first array

    // value
    printf("%d %d %d\n", **ptr, **(ptr + 1), **(ptr + 2));
    printf("%d %d %d\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));
    printf("%d %d %d\n", ptr[0][0], ptr[1][2], ptr[2][3]);

    return 0;
}