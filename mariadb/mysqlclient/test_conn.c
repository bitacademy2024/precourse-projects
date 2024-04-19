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
        exit(1);
    }

    printf("connection success!!!\n");

    // close connection
    mysql_close(conn);

    return 0;
}
