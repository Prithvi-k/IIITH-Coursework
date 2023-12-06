#include <stdio.h>

int main()
{
    int var = 10;
    int *ptr;
    int **second_ptr;

    ptr = &var;
    second_ptr = &ptr;

    printf("var = %d\n", var);
    printf("value of var with ptr = %d\n", *ptr);
    printf("value of var with second_ptr = %d\n", **second_ptr);

    // one `*` is analogous to 'removing' one `&`

    return 0;
}