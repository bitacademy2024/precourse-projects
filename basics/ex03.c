#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0;
    fputs("두 수 입력:", stdout);
    scanf("%d %d", &num1, &num2);

    printf("%d, %d\n", num1, num2);
}