#include <stdio.h>
#include <stdlib.h> // header file for malloc function

int main()
{
    int *var;

    var = (int *)malloc(sizeof(int));
    // malloc returns void pointer
    // hence we can typecast var pointer to any datatype
    printf("Malloc pointer: %p\n", malloc);

    printf("Current random value at var: %d\n", *var);

    *var = 5;
    printf("New value at var: %d\n", *var);
    return 0;
}