#include <stdio.h>

int main()
{
    int num = 0;
    fputs("수 입력:", stdout);
    scanf("%d", &num);

    printf("%d\n", num);
}