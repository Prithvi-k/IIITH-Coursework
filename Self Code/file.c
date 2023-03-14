#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fPtr;
    fPtr = fopen("Self Code/file.txt", "a+");

    // char str[10];
    // for (int i = 0; i < 5; i++)
    // {
    //     scanf("%c", &str[i]);
    // }

    // fprintf(fPtr, "%s ", str);

    rewind(fPtr);
    char c;
    while (c = fgetc(fPtr) != EOF)
    {
        printf("%c", c);
    }
    printf("\nEnd\n");

    return 0;
}