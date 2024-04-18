
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    srand(time(NULL));

    while(1)
    {
        int r_num = rand() % 100 + 1;
        printf("%d\n", r_num);

        if(r_num >= 100) {
            break;
        }
    }
}