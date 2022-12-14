#include <stdio.h>

int main()
{
    int var = 10;
    int *ptr;
    int **second_ptr;

    ptr = &var;
    second_ptr = &ptr;

    printf("var = %d\n", var);
    

    return 0;
}