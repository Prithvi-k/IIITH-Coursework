#include <stdio.h>

typedef struct Point
{
    int x;
    int y;
} Point;

// analogous to typedef int xyz;
// struct Point {} ~ int
// Point after } ~ xyz

int main()
{
    Point p = {.x = 320, .y = 260};
    printf("X coordinate of p is %d\n", p.x);
    printf("Y coordinate of p is %d\n", p.y);
    return 0;
}