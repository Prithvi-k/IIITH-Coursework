#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char convert_to_uppercase(char character)
{
    if (character >= 'a' && character <= 'z')
    {
        return character -= 32;
    }
    return character;
}

int main()
{
    FILE *fPtr;
    fPtr = fopen("/home/prithvi/Documents/CPro/Assignments/Assignment 4/to_capitalise.txt", "r+");

    if (!fPtr)
    {
        printf("File not found");
        return 0;
    }

    // create a temporary file
    FILE *temp = fopen("temp.txt", "w");
    if (!temp)
    {
        printf("Unable to create temporary file");
        return 0;
    }

    int i = 0;
    char c;
    char word[100];
    while ((c = fgetc(fPtr)) != EOF)
    {
        if (c == ' ' || c == '\n')
        {
            word[i] = '\0';
            word[0] = convert_to_uppercase(word[0]);
            word[strlen(word) - 1] = convert_to_uppercase(word[strlen(word) - 1]);
            fprintf(temp, "%s ", word);
            i = 0;
        }
        else
        {
            word[i] = c;
            i++;
        }
    }
    if (i > 0)
    {
        word[i] = '\0';
        word[0] = convert_to_uppercase(word[0]);
        word[strlen(word) - 1] = convert_to_uppercase(word[strlen(word) - 1]);
        fprintf(temp, "%s ", word);
    }

    // close both the files
    fclose(fPtr);
    fclose(temp);

    // delete the original file
    remove("/home/prithvi/Documents/CPro/Assignments/Assignment 4/to_capitalise.txt");
    // rename the temporary file to original file
    rename("temp.txt", "/home/prithvi/Documents/CPro/Assignments/Assignment 4/to_capitalise.txt");
    return 0;
}
