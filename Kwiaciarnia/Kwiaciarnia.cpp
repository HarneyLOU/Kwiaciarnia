#include "pch.h"


#define SERVER "localhost"  // As your code and database are on same computer
#define USER "root" // user name by which you want to access the database ( database user name- not server)
#define PASSWORD ""
#define DATABASE "kwiaciarnia"  // the database name in the database server

MYSQL mysql;

using namespace std;


int main()
{
	
	mysql_init(&mysql); // incjalizacja

	if (mysql_real_connect(&mysql, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0))
	{
		Menu *men = new Menu("");
		men->MenuLogowania(mysql);
	}

	else
		printf("Blad polaczenia z baza MySQL: %d, %s\n", mysql_errno(&mysql), mysql_error(&mysql));

	return 0;
}

