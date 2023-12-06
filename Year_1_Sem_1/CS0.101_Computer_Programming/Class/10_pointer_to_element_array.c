#include <stdio.h>

int main()
{
    int a[5] = {11, 21, 31, 41, 51};
    int *ptr = a;
    // int *ptr = &a[0]; // same as above

    // using for loop to print array elements using addition arithmetic on pointer
    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("%d --> ", *(ptr + i)); // prints value of each element
        printf("%p --> ", (ptr + i));  // prints memory address of each element
        printf("%d \n", (ptr + i));    // prints memory address of each element
                                       // in decimal format
                                       // gives a warning cause not using %p,
                                       // will ouput decimal value of memory address (originally in hexadecimal)
    }

    printf("\n");

    return 0;
}