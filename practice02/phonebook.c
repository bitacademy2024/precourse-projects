#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonebook.h"

phone arr_phone[100];
int cur_idx = 0;

void print_message(char* message)
{
	printf("전화번호부>> %s \n", message);
}

void print_usage()
{
	fputs("전화번호부>> (l)전체 항목 보기 (i)추가하기 (d)삭제 (q)종료 : ", stdout);
}

void list()
{
	print_message("전체항목");
	
	for(int i = 0; i < cur_idx; i++)
	{
		if( arr_phone[i].used == 0 )
		{
			continue;
		}

		printf("[%d] 이름:%s, 전화번호:%s \n", i+1, arr_phone[i].name, arr_phone[i].tel );
	}
}

void insert()
{
	print_message("추가하기");

	fputs("이름:", stdout);
	scanf("%s", arr_phone[cur_idx].name);
	__fpurge(stdin);

	fputs("전화번호:", stdout);
	scanf("%s", arr_phone[cur_idx].tel);
	__fpurge(stdin);

	arr_phone[cur_idx].used = 1;

	cur_idx++;

	print_message("성공적으로 추가되었습니다.");
}

void del()
{
	print_message("삭제");

	char name[20];
	fputs("이름:", stdout);
	scanf("%s", name);
	__fpurge(stdin);

	for(int i = 0; i < cur_idx; i++)
	{
		if( strcmp(arr_phone[i].name, name) == 0 )
		{
			print_message("성공적으로 삭제 하였습니다.");
			arr_phone[i].used = 0;

			return;
		}
	}

	print_message("성공적으로 삭제 하였습니다.");
}

void quit()
{
	exit(0);
}

void phonebook()
{
	char command;

	print_usage();

	scanf("%c", &command); 
	__fpurge(stdin);

	switch(command)
	{
		case 'l' : 
			list();
			break;
		case 'i' :
			insert();
			break;
		case 'd' : 
			del();
			break;
		case 'q' :
			quit();
			break;
		default  :
			print_message("알 수 없는 명령입니다");
			break;
	}
}
