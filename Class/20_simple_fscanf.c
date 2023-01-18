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

    int a = 0, b = 0, c = 0;

    fscanf(fPtr, "%d, %d, %d", &a, &b, &c);

    printf("%d, %d, %d", a, b, c);

    return 0;
}