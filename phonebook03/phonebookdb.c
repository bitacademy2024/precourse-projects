#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include "phonebookdb.h"

const char* host = "192.168.0.26";
const int port = 3306;
const char* user = "eluon";
const char* password = "eluon";
const char* db = "eluondb";

int phonebookdb_fetch_all(phone** phones)
{
    MYSQL* conn = NULL;

    if((conn = mysql_init(0)) == NULL)
    {
        fprintf(stderr, "unable to initialize connection structure\n");
        return -1;
    }

    if(mysql_real_connect(conn, host, user, password, db, port, NULL, 0) == NULL)
    {
        fprintf(stderr, "error connecting to server: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    char* sql = "select name, tel from phonebook order by name asc";
    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "error executing sql: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if(result == NULL)
    {
        fprintf(stderr, "error executing sql: %s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    int num_rows = mysql_num_rows(result);
    *phones = (phone*)malloc(num_rows * sizeof(phone));
    
    for(int i = 0; i < num_rows; i++)
    {
        MYSQL_ROW row = mysql_fetch_row(result);

        phone* it = *phone + i;
        strcpy(it->name, row[0]);
        strcpy(it->tel, row[1]);
    } 

    mysql_free_result(result);
    mysql_close(conn);

    return num_rows;    
}

