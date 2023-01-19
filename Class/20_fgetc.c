#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fPtr;

    char ch;

    // Open file in read mode
    fPtr = fopen("/home/prithvi/Documents/CPro/Class/file1.txt", "r");

    // fopen() return NULL if last operation was unsuccessful
    if (fPtr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully. Reading file contents character by character. \n");

    do
    {
        // Read single character from file
        ch = fgetc(fPtr);

        // Print character read on console
        putchar(ch);
    } while (ch != EOF);

    fclose(fPtr);

    return 0;
}