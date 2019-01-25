#include "pch.h"
#include "Klient.h"


Klient::Klient()
{
}


Klient::~Klient()
{
}

void Klient::Wyswietl(MYSQL &mysql)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	cout.width(10);
	cout << "login";
	cout.width(20);
	cout << "Nazwisko";
	cout.width(20);
	cout << "Imie";
	cout.width(18);
	cout << "Miasto";
	cout.width(18);
	cout << "Adres";
	cout.width(18);
	cout << "Telefon";
	cout.width(18);
	cout << "E-Mail"<<endl;

	string query = "SELECT `login`, `Nazwisko`, `Imie`, `Miasto`, `Adres`, `Telefon`, `Mail` FROM `klienci` WHERE 1";

	mysql_query(&mysql, query.c_str());

	idZapytania = mysql_store_result(&mysql);

	while ((wiersz = mysql_fetch_row(idZapytania)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania); i++)
		{
			if(i!=0)cout.width(16);
			cout << wiersz[i] << " | ";
		}
		cout << endl;
	}
}

void Klient::Wyswietl(MYSQL &mysql, string query)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	cout.width(10);
	cout << "login";
	cout.width(20);
	cout << "Nazwisko";
	cout.width(20);
	cout << "Imie";
	cout.width(18);
	cout << "Miasto";
	cout.width(18);
	cout << "Adres";
	cout.width(18);
	cout << "Telefon";
	cout.width(18);
	cout << "E-Mail" << endl;

	if (query == "0") query = "SELECT `login`, `Nazwisko`, `Imie`, `Miasto`, `Adres`, `Telefon`, `Mail` FROM `klienci` WHERE 1";

	mysql_query(&mysql, query.c_str());

	idZapytania = mysql_store_result(&mysql);

	while ((wiersz = mysql_fetch_row(idZapytania)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania); i++)
		{
			cout.width(16);
			cout << wiersz[i] << " | ";
		}
		cout << endl;
	}
}


void Klient::Usun(MYSQL &mysql)
{
	string login;

	cout << "Podaj login:";
	getline(cin, login);
	string query = "DELETE FROM `klienci` WHERE login = " + login;
	mysql_query(&mysql, query.c_str());

}

void Klient::Edytuj(MYSQL &mysql)
{
	string query;
	string login;
	
		Znajdz(mysql);

		cout << "Podaj login klienta: ";
		getline(cin, login);
	
	
		 query = "SELECT `login`, `Nazwisko`, `Imie`, `Miasto`, `Adres`, `Telefon`, `Mail` FROM `klienci` WHERE login='" + login + "'";
	 	Wyswietl(mysql, query);
		cout << "Edycja: " << endl;
		cout << "1. Nazwisko" << endl;
		cout << "2. Imie" << endl;
		cout << "3. Miasto" << endl;
		cout << "4. Adres" << endl;
		cout << "5. Telefon" << endl;
		cout << "6. E-mail" << endl;

		string wybor;
		getline(cin, wybor);


		if (wybor == "1")
		{
			string zmiana;
			cout << "Podaj nazwisko: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Nazwisko`='" + zmiana + "' WHERE login='"+login+"'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "2")
		{
			string zmiana;
			cout << "Podaj imie: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Imie`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "3")
		{
			string zmiana;
			cout << "Podaj miasto: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Miasto`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "4")
		{
			string zmiana;
			cout << "Podaj adres: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Adres`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "5")
		{
			string zmiana;
			cout << "Podaj telefon: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Telefon`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "6")
		{
			string zmiana;
			cout << "Podaj adres poczty elektronicznej: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Mail`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}

}

void Klient::Edytuj(MYSQL &mysql, string login)
{
	string query;
		query = "SELECT `login`, `Nazwisko`, `Imie`, `Miasto`, `Adres`, `Telefon`, `Mail` FROM `klienci` WHERE login='" + login + "'";
		Wyswietl(mysql, query);
		cout << "Edycja: " << endl;
		
		cout << "1. Miasto" << endl;
		cout << "2. Adres" << endl;
		cout << "3. Telefon" << endl;
		cout << "4. E-mail" << endl;

		string wybor;
		getline(cin, wybor);

		
		if (wybor == "1")
		{
			string zmiana;
			cout << "Podaj miasto: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Miasto`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "2")
		{
			string zmiana;
			cout << "Podaj adres: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Adres`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "3")
		{
			string zmiana;
			cout << "Podaj telefon: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Telefon`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "4")
		{
			string zmiana;
			cout << "Podaj adres poczty elektronicznej: ";
			getline(cin, zmiana);
			query = "UPDATE `klienci` SET `Mail`='" + zmiana + "' WHERE login='" + login + "'";
			mysql_query(&mysql, query.c_str());
		}

}


void Klient::Znajdz(MYSQL &mysql)
{
	string query;
	string szukaj;
	cout << "Podaj nazwisko klienta, by wyszukac: ";
	getline(cin, szukaj);
	if (szukaj == "/all")
	{
		Wyswietl(mysql);
	}
	else
	{
		query = "SELECT `login`, `Nazwisko`, `Imie`, `Miasto`, `Adres`, `Telefon`, `Mail` FROM `klienci` WHERE Nazwisko like '%" + szukaj + "%'";	
		Wyswietl(mysql, query);
	}
}