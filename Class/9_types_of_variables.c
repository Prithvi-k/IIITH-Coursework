#include <stdio.h>

int fun();
int fun_static();
int fun_global();

int count = 0;

int main()
{
    printf("1. fun():\n");
    printf("    %d ", fun());
    printf("%d\n\n", fun());

    printf("2. fun_static():\n");
    printf("    %d ", fun_static());
    printf("%d\n\n", fun_static());

    printf("3. fun_global():\n");
    printf("    %d ", fun_global());
    printf("%d\n\n", fun_global());
    return 0;
}

int fun()
{
    int count = 0;
    count++;
    return count;
}

int fun_static()
{
    static int count = 0;
    count++;
    return count;
}

int fun_global()
{
    count++;
    return count;
}