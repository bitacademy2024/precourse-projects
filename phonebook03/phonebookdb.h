typedef struct phone
{
    long no;
	char name[20];
	char tel[20];
} phone;

int phonebookdb_fetch_all(phone**);