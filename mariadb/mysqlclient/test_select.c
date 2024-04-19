#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main()
{
    // initialize connection
    MYSQL* conn = NULL;

    if(!(conn = mysql_init(0)))
    {
        fprintf(stderr, "unable to initialize connection structure\n");
        exit(1);
    }

    // coonect to mariadb(eluondb)
    if(mysql_real_connect(
        conn,           // MYSQL structure
        "192.168.0.26", // host
        "eluon",        // user
        "eluon",        // password
        "eluondb",      // database
        3306,           // port
        NULL,           // path to socket file
        0               // extra options            
    ) == NULL)
    {
        fprintf(stderr, "error connecting to server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // execute SQL
    char* sql = "select name, tel from phonebook order by name asc";

    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "error executing sql: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if(result == NULL)
    {
        fprintf(stderr, "error executing sql: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // processing result01

    // int num_fields = mysql_num_fields(result);
    // MYSQL_ROW row;
    // while((row = mysql_fetch_row(result)))
    // {   
    //     for(int i = 0; i < num_fields; i++)
    //     {
    //         printf("%s ", row[i] ? row[i] : "NULL");
    //     }
    //     printf("\n");
    // } 

    // processing result02
    int num_rows = mysql_num_rows(result);
    for(int i = 0; i < num_rows; i++)
    {
        MYSQL_ROW row = mysql_fetch_row(result);
        printf("%s %s\n", row[0], row[1]);
    } 

    mysql_free_result(result);


    // close connection
    mysql_close(conn);

    return 0;
}
