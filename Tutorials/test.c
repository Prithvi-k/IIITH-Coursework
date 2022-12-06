#include <stdio.h>

int main()
{
    int i = 0;

    /* for (printf("1"); printf("2"); printf("3"))
    {
        i++;
        if (i == 3)
        {
            break;
        }

        printf("loop\n");
    } //loop runs fine till break when i == 3
    */

    /* while (printf("Hello world\n"))
    {
        printf("Hi!\n");
    } // infinite loop since condition != 0
    */

    int res = printf("Hello ") + printf("World\n");
    printf("%d\n", res);

    return 0;
}