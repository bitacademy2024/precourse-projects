#include <stdio.h>

void reset(int* n)
{
    *n = 0;
}

int main()
{
    int i = 10;
    
    printf("before:%d\n", i);
    reset(&i);
    printf("after:%d\n", i);

    return 0;
}