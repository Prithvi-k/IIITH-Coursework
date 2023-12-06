#include <stdio.h>

int main()
{
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);
    // Takes in characters until any whitespace is encountered
    // even if there is still space in the array
    // whitespace = space, tab, newline, etc.
    printf("You entered: %s\n", string);

    /*
    Input: test
    Output: test

    Input: te st
    Output: te

    Input: t
           e
           s
           t
    Output: t

    */

    return 0;
}