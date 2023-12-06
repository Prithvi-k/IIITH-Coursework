#include <stdio.h>

int main()
{
    int a = 0;
    /*
    int *pointer; // initialising pointer
    pointer = &a; // assigning memory address of variable
    */
    int *pointer = &a;

    printf("a = %d\n", a);
    printf("pointer = %p\n", pointer);   // memory address of a
    printf("*pointer = %d\n", *pointer); // 'dereferencing' i.e. returns value at that particular address

    *pointer = 15; // value at address is now 15
    printf("a = %d\n", a);
    printf("*pointer = %d\n", *pointer);

    return 0;
}