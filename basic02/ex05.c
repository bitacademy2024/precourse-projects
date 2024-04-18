#include <stdio.h>
#include "ex05.h"

// struct point
// {
//     int x;
//     int y;
// };

// void point_test()
// {
//     struct point p1, p2;

//     p1.x = 10;
//     p1.y = 20;

//     p2.x = 100;
//     p2.y = 200;
// }

typedef struct circle
{
    point p;
    double radius;
} circle;

void circle_test()
{
    circle c1 = {10, 10, 5};
    circle c2 = {{100, 200}, 50};
    printf("원 c2(x: %d, y: %d, radius: %f)\n", c2.p.x, c2.p.y, c2.radius);
}

int main()
{
//    point_test();
    circle_test();
    return 0;
}