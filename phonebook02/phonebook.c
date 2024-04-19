#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonebook.h"

phone* head;

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

	int idx = 1;
	phone* it = head;
	while(it->next != NULL)
	{
		printf("[%d] 이름:%s, 전화번호:%s \n", idx++, it->next->name, it->next->tel );
		it = it->next;
	}
}

void insert()
{
	print_message("추가하기");

	char name[20];
	char tel[20];

	fputs("이름:", stdout);
	scanf("%s", name);
	__fpurge(stdin);

	fputs("전화번호:", stdout);
	scanf("%s", tel);
	__fpurge(stdin);

	phone* find = head;
	while(find->next != NULL)
	{
		find = find->next;
	}

	phone* new_phone = (phone*)malloc(sizeof(phone));
	strcpy(new_phone->name, name);
	strcpy(new_phone->tel, tel);

	find->next = new_phone;
	new_phone->next = NULL;

	print_message("성공적으로 추가되었습니다.");
}

void del()
{
	print_message("삭제");

	char name[20];
	fputs("이름:", stdout);
	scanf("%s", name);
	__fpurge(stdin);

	phone* find = head;
	while(find->next != NULL)
	{
		if(strcmp(find->next->name, name) == 0)
		{
			break;
		}

		find = find->next;
	}

	if(find->next != NULL)
	{
		phone* temp = find->next->next;
		free(find->next);
		find->next = temp;
	}
	else
	{
		print_message("삭제 대상이 없음");
	}
}

void quit()
{
	exit(0);
}

void phonebook()
{
	head = (phone*)malloc(sizeof(phone));
	head->next = NULL;

	while(1)
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
}
