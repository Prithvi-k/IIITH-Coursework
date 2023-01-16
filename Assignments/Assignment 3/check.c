#include <stdio.h>
#include <string.h>

int main()
{
    char x[10];
    scanf("%s", x);
    int n = strlen(x);

    for (int i = 0; i < n; i++)
    {
        char element = x[i];
        int ascii_element = (int)x[i];
        printf("ASCII value of %c is %d\n", element, ascii_element);
        printf("Adjusted ascii is %d\n", (ascii_element - 97));
    }

    return 0;
}