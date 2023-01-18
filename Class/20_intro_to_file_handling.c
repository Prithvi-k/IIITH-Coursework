#include <stdio.h>
#include <stdlib.h>

int main()
{
    // File pointer to hold reference to file
    FILE *fPtr;

    // Open file in write mode (`w`)
    // If file does not exist, it will be created
    // Specify path of file to be created relative to current directory
    fPtr = fopen("/home/prithvi/Documents/CPro/Class/file1.txt", "w");

    // fopen() return NULL if last operation was unsuccessful
    if (fPtr == NULL)
    {
        // Unable to open file hence exit
        printf("Unable to create file.\n");
        exit(0);
    }

    // Write contents to file

    // Close file to save file contents
    fclose(fPtr);

    return 0;
}