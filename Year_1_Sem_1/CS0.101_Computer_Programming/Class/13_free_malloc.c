#include <stdio.h>
#include <stdlib.h>

int main()
{
    // allocting memory
    int *var = (int *)malloc(10 * sizeof(int));

    // freeing memory
    free(var);

    return 0;
}