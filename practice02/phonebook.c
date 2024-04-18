#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonebook.h"

phone arr_phone[100];
int cur_index = 0;

void print_message(char* message) {
    printf("전화번호>> %s\n", message);
}

void print_usage()
{
    fputs("(l)전체항목 (i)추가 (d)삭제 (q)종료 : ", stdout);
}

void list()
{
    print_message("전체항목");
}

void quit() {
    exit(0);
}

void phonebook() {
    char cmd;

    print_usage();

    scanf(" %c", &cmd);
    __fpurge(stdin);

    switch(cmd)
    {
        case 'l':
            // list();
            break;    
        case 'i':
            // insert();
            break;    
        case 'd':
            // del();
            break;    
        case 'q':
            quit();
            break;
        default:
            print_message("알 수 없는 명령입니다.");
            break;    
    }
}