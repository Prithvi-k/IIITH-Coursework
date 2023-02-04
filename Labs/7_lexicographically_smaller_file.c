#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Given two files as input, write a program to check which file is lexicographically smaller */

int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("7_file1.txt", "r");
    fp2 = fopen("7_file2.txt", "r");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    char c1, c2;
    while ((c1 = fgetc(fp1)) != EOF && (c2 = fgetc(fp2)) != EOF)
    {
        if (c1 < c2)
        {
            printf("File 1 is lexicographically smaller\n");
            break;
        }
        else if (c1 > c2)
        {
            printf("File 2 is lexicographically smaller\n");
            break;
        }
    }

    if (c1 == EOF && c2 == EOF)
    {
        printf("Files are duplicates\n");
    }
    else if (c1 == EOF)
    {
        printf("File 1 is lexicographically smaller\n");
    }
    else if (c2 == EOF)
    {
        printf("File 2 is lexicographically smaller\n");
    }    

    fclose(fp1);
    fclose(fp2);

    return 0;
}