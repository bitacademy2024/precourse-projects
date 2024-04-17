#include <stdio.h>

int max(int, int, int);

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;
    fputs("3 개의 수 입력:", stdout);
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("%d", max(num1, num2, num3));
}

int max(int n1, int n2, int n3)
{
    return n3;
}