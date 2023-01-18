#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fPtr;

    fopen("text1.txt", "w");

    // fputc('c', fPtr);
    // fputs("\nHello", fPtr);
    fprintf(fPtr, "\n%d", 10);

    fclose(fPtr);

    return 0;
}