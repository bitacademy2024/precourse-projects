#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i = 10;
    printf("%d@%lx\n", i, (unsigned long)&i);

    int* p1 = &i;
    printf("%d@%lx@%lx\n", *p1, (unsigned long)p1, (unsigned long)&p1);

    *p1 = 30;
    printf("%d %d\n", i, *p1);

    printf("pointer 변수(p1)의 크기: %ld, int변수의 크기: %ld\n", sizeof(p1), sizeof(i));

    char c = 'A';
    char* p2 = &c;
    printf("pointer 변수(p2)의 크기: %ld, char변수의 크기: %ld\n", sizeof(p2), sizeof(c));

    // 오류
    // &i = p1;

    return 0;
}