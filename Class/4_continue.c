#include <stdio.h>

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        if (i == 6)
        {
            continue; //when true, skips out all of the remaining code
            
        }
        else
        {
            printf("%d, ", i);
        }
    }

    printf("\n");
    return 0;
}