#include <stdio.h>

int main()
{
    int i[] = {10, 20, 30, 40};

    printf("배열의 크기: %ld\n",  sizeof(i)/sizeof(int));
    printf("%lx\n", (unsigned long)i);

    int* p1 = i;
    printf("%d %d\n", *p1, i[0]);

    int* p2 = &i[0];
    printf("%d %d\n", *p2, i[0]);

    // 포인터 변수의 증가
    printf("%d@%lx\n", *p1, (unsigned long)p1);
    p1++;
    printf("%d@%lx\n", *p1, (unsigned long)p1);
    p1 += 1;
    printf("%d@%lx\n", *p1, (unsigned long)p1);
    p1 = p1 + 1;
    printf("%d@%lx\n", *p1, (unsigned long)p1);

    // cf
    printf("%d@%lx\n", *(p2+0), (unsigned long)p2);
    printf("%d@%lx\n", *(p2+1), (unsigned long)p2);
    printf("%d@%lx\n", *(p2+2), (unsigned long)p2);
    printf("%d@%lx\n", *(p2+3), (unsigned long)p2);

}