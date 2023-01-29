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
    FILE *temp;
    fPtr = fopen("Assignments/Assignment 4/to_capitalise.txt", "r");
    if (!fPtr)
    {
        printf("File not found");
        return 0;
    }

    // create a temporary file
    temp = fopen("Assignments/Assignment 4/temp.txt", "w");

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
            // c is a space or a newline => end of word
            word[i] = '\0';
            // Capitalise first and last character
            word[0] = convert_to_uppercase(word[0]);
            word[strlen(word) - 1] = convert_to_uppercase(word[strlen(word) - 1]);
            // Print word
            if (c == '\n')
            {
                printf("%s\n", word);
                fprintf(temp, "%s\n", word);
            }
            else
            {
                printf("%s ", word);
                fprintf(temp, "%s ", word);
            }
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
        printf("%s ", word);
        fprintf(temp, "%s ", word);
    }

    fclose(fPtr);
    fclose(temp);

    fPtr = fopen("Assignments/Assignment 4/to_capitalise.txt", "w");
    temp = fopen("Assignments/Assignment 4/temp.txt", "r");

    if (!fPtr || !temp)
    {
        printf("Unable to open file");
        return 0;
    }

    // Copy contents of temp.txt to to_capitalise.txt
    while ((c = fgetc(temp)) != EOF)
    {
        fputc(c, fPtr);
    }

    fclose(fPtr);
    fclose(temp);
    remove("Assignments/Assignment 4/temp.txt");

    // Check
    fPtr = fopen("Assignments/Assignment 4/to_capitalise.txt", "r");
    if (!fPtr)
    {
        printf("File not found");
        return 0;
    }

    printf("\n\n");
    while ((c = fgetc(fPtr)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fPtr);
    return 0;
}
