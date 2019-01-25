#include "pch.h"
#include "Oferta.h"


Oferta::Oferta()
{
}


Oferta::~Oferta()
{
}

void Oferta::Wyswietl(MYSQL &mysql, string query)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	cout.width(8);
	cout << "ID oferty";
	cout.width(25);
	cout << "Nazwa";
	cout.width(20);
	cout << "Cena"<<endl;
	

	if (query == "0") query = "SELECT * FROM `oferta` WHERE 1 ORDER BY Nazwa";

	mysql_query(&mysql, query.c_str());

	idZapytania = mysql_store_result(&mysql);

	while ((wiersz = mysql_fetch_row(idZapytania)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania); i++)
		{
			if (i != 0) cout.width(30); else cout.width(5);
			cout << left << wiersz[i] << " | ";
		}
		cout << endl;
	}

}

void Oferta::Dodaj(MYSQL &mysql)
{
	string nazwa;
	string cena;

	cout << "Nazwa: ";
	getline(cin, nazwa);
	cout << "Cena: ";
	getline(cin, cena);

	string query = "INSERT INTO `oferta`(`Nazwa`, `Cena`) VALUES ('" + nazwa + "', '" + cena + "')";
	mysql_query(&mysql, query.c_str());
	cout << "Pomyslnie dodano";
}

void Oferta::Usun(MYSQL &mysql)
{
	string id;

	cout << "Podaj identyfikator oferty:";
	cin >> id;
	string query = "DELETE FROM `oferta` WHERE IDK = " + id;
	mysql_query(&mysql, query.c_str());
	cout << "Pomyslnie usunieto";
}


void Oferta::Znajdz(MYSQL &mysql)
{
	string query;
	string szukaj;
	cout << "Podaj ID lub nazwe oferty, by wyszukac: ";
	getline(cin, szukaj);
	if (szukaj == "/all")
	{
		Wyswietl(mysql);
	}
	else
	{
		if (int(szukaj[0]) >= 48 && int(szukaj[0]) <= 57)
			query = "SELECT * FROM `oferta` WHERE IDK like '%" + szukaj + "%'";
		else
			query = "SELECT * FROM `oferta` WHERE Nazwa like '%" + szukaj + "%'";
		Wyswietl(mysql, query);
	}
}

void Oferta::Edytuj(MYSQL &mysql)
{
		Znajdz(mysql);

		string id;
		cout << "Podaj ID oferty: ";
		getline(cin, id);

		cout << "Edycja: " << endl;

		cout << "1. Nazwa" << endl;
		cout << "2. Cena" << endl;

		string wybor;
		getline(cin, wybor);
		string query;
		if (wybor == "1")
		{
			string zmiana;
			cout << "Podaj nowa nazwe: ";
			getline(cin, zmiana);
			query = "UPDATE `oferta` SET `Nazwa`='" + zmiana + "' WHERE IDK=" + id;
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "2")
		{
			string zmiana;
			cout << "Podaj nowa cene: ";
			getline(cin, zmiana);
			query = "UPDATE `oferta` SET `Cena`='" + zmiana + "' WHERE IDK=" + id;
			mysql_query(&mysql, query.c_str());
		}

	}
