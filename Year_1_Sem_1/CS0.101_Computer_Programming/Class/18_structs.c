#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point p = {.x = 320, .y = 260};
    printf("X coordinate of p is %d\n", p.x);
    printf("Y coordinate of p is %d\n", p.y);
    return 0;
}