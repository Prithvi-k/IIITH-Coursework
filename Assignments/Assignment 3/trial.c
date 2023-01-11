#include <stdio.h>
#include <string.h>

int main()
{
    char name1[3] = "ab";

    char name2[3] = "ac";
    printf("name1: %s\tname2: %s\n", name1, name2);

    printf("%d\n", strcmp(name1, name2));
    return 0;
}