#include <stdio.h>

int main()
{
    int arr[5] = {3, 5, 7, 9, 11};

    int(*ptr)[5];

    // both `arr` and `&arr` return the address of the first element of the array
    // but for pointer to an array, we need to specify with `&arr`
    ptr = &arr;
    printf("Address of the first element of the array: %p\n", ptr);
    printf("Address of first element: %p\n", *ptr); // `*ptr` = arr = address of first element
    printf("Value of the first element: %d\n", **ptr);
    printf("Address of second element: %p\n", *ptr + 1);
    printf("Value of 2nd element: %d\n", *(*ptr + 1));

    // printing elements of array using addition arithmetic on pointer + dereferencing
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(*ptr + i));

        /*

        *ptr refers to the address of the first element of the array
        *ptr + i refers to the address of the ith element of the array
        *(*ptr + i) refers to the value at the ith element of the array

        */
    }

    printf("\n");
    return 0;
}