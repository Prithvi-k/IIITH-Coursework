#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main()
{
    FILE *fPtr;
    char buffer[BUFFER_SIZE];
    int totalRead = 0;

    fPtr = fopen("/home/prithvi/Documents/CPro/Class/file1.txt", "r");

    if (fPtr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, fPtr) != NULL)
    {
        // Total character count
        totalRead += strlen(buffer);

        // Replace last character with null character if it is newline
        // This is done to avoid printing extra new line
        buffer[totalRead - 1] = ((buffer[totalRead - 1] == '\n') ? '\0' : buffer[totalRead - 1]);

        // Print line read from file
        printf("%s", buffer);
    }

    printf("\nTotal characters = %d\n", totalRead);

    fclose(fPtr);
    return 0;
}