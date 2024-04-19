#include <stdio.h>
#include <stdlib.h>

int reset(int** n)
{
    int count = 5;
    *n = (int*)malloc(count * sizeof(int));

    for(int i = 0; i < 5; i++){
        *(*n+i) = 0;
    }

    return count;
}

int main()
{
    int* i = NULL;
    
    int count = reset(&i);
    
    for(int j = 0; j < count; j++)
    {
        printf("%d\n", *(i+j));
    }

    return 0;
}