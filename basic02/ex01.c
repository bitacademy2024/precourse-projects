#include <stdio.h>
#include <stdbool.h>

int main()
{
    char c = 'A';
    printf("%c, %d\n", c, c);

    bool b = true;
    printf("%d, %ld\n", b, sizeof(unsigned char));

    return 0;
}