#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        fputs("usage: test_insert name tel\n", stdout);
        exit(0);
    }

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
    char sql[200];
    sprintf(sql, "insert into phonebook values(null, '%s', '%s')", argv[1], argv[2]);

    if(mysql_query(conn, sql))
    {
        fprintf(stderr, "error executing sql: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // close connection
    mysql_close(conn);

    return 0;
}
