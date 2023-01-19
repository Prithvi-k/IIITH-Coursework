#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fPtr;

    fopen("/home/prithvi/Documents/CPro/Class/text.txt", "r");

    if (fPtr == NULL)
    {
        printf("File not found");
        exit(0);
    }

    char a[6];

    // fscanf(fPtr, "%s", a);

    fgets(fPtr, 6, a);

    printf("%s", a);

    return 0;
}