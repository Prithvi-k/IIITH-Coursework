#include <stdio.h>

int main()
{
    int a[5] = {5, 1, 3, 91, 3};
    int *ptr = a;

    //all of the following print the same values
    // ptr == &a[0] == a == &a
    printf("ptr : %p, &a[0] : %p, a : %p, &a : %p\n", ptr, &a[0], a, &a);

    // `&a[n]` gives address of element at nth index of array

    return 0;
}