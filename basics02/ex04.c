#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = {'x', 'x', 'x', 'x', 'x', 'x', 'x'};
    char s2[] = {'h', 'e', 'l', 'l', 'o'};

    printf("%s@%lx\n", s1, (unsigned long)s1);
    printf("%s@%lx\n", s2, (unsigned long)s2);

    char* s3 = "xxxxxxx";
    char* s4 = "hello";

    printf("%s@%lx\n", s3, (unsigned long)s3);
    printf("%s@%lx\n", s4, (unsigned long)s4);

    char* s5 = s4;
    printf("%c %c\n", *(s5+1), *(s2+1));

    char s6[] = "hello";
    printf("%s, %ld, %ld, %c, %c\n", s6, strlen(s6), sizeof(s6), s6[2], *(s6+2));


    return 0;
}