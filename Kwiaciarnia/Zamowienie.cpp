#include "pch.h"
#include "Zamowienie.h"


Zamowienie::Zamowienie()
{
}


Zamowienie::~Zamowienie()
{
}

void Zamowienie::Wyswietl(MYSQL &mysql, string query)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	if (query == "0") query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE k.login = z. login and z.IDK= o.IDK ORDER BY z.Data DESC";

	cout << "Nr zamowienia";
	cout.width(20);
	cout << "Nazwisko";
	cout.width(10);
	cout << "ID oferty";
	cout.width(15);
	cout << "Nazwa oferty";
	cout.width(16);
	cout << "Sztuk";
	cout.width(9);
	cout << "Kwota";
	cout.width(16);
	cout << "Data";
	cout.width(16);
	cout << "Status" << endl<<endl;
	cout << "__________________________________________________________________________________________________________________" << endl;

	mysql_query(&mysql, query.c_str());

	idZapytania = mysql_store_result(&mysql);

	while ((wiersz = mysql_fetch_row(idZapytania)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania); i++)
		{
			if (i == 0) cout.width(5);
			if (i == 1) cout.width(25);
			if (i == 2) cout.width(3);
			if (i == 3) cout.width(25);
			if (i == 4) cout.width(5);
			if (i == 5) cout.width(8);
			if (i == 6) cout.width(18);
			if (i != 7) cout << wiersz[i] << " | ";
			else  cout << wiersz[i] << "   ";;

		}
		cout << endl;
	}
}

void Zamowienie::Dodaj(MYSQL &mysql, string login)
{
	if (login == "admin")
	{
		cout << "Podaj login: ";
		getline(cin, login);
		
	}
	if (!CzyLogin(login, mysql))
	{

		string idk;
		string sztuk;

		cout << "Podaj ID oferty: ";
		getline(cin, idk);
		cout << "Podaj liczbe sztuk: ";
		getline(cin, sztuk);

		//Pobranie ceny oferty
		MYSQL_RES *idZapytania;
		MYSQL_ROW  wiersz;

		string query = "SELECT `Cena` FROM `oferta` WHERE IDK = " + idk;
		mysql_query(&mysql, query.c_str());

		idZapytania = mysql_store_result(&mysql);

		wiersz = mysql_fetch_row(idZapytania);
		double cena = stod(wiersz[0]);

		//Cena ofery x liczba sztuk

		cena = cena * (stoi(sztuk));
		string cenas = to_string(cena);

		query = "INSERT INTO `zamowienie`(`login`, `IDK`, `Sztuk`, `Kwota`, `Data`) VALUES ('" + login + "', " + idk + ", " + sztuk + ", " + cenas + ", SYSDATE())";
		mysql_query(&mysql, query.c_str());

		if (login != "admin") cout << "Zamowienie zlozone. Zrealizujemy je po otrzymaniu wplaty." << endl;
	}
	else
	{
		Sleep(1000);
		cout << "Nie ma takiego loginu" << endl;
	}
}

void Zamowienie::Edytuj(MYSQL &mysql)
{
	Znajdz(mysql);
	string id;
	string query;
	cout << "Podaj ID zamowienia: ";
	getline(cin, id);

		cout << "Edycja statusu: " << endl;

		cout << "1. Niepotwierdzone" << endl;
		cout << "2. Oplacone" << endl;
		cout << "3. Zrealizowane" << endl;
		cout << "4. Anulowane" << endl;

		string wybor;
		getline(cin, wybor);


		if (wybor == "1")
		{
			query = "UPDATE `zamowienie` SET `Status`='Niepotwierdzone' WHERE IDZ='" + id + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "2")
		{
			query = "UPDATE `zamowienie` SET `Status`='Oplacone' WHERE IDZ='" + id + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "3")
		{
			query = "UPDATE `zamowienie` SET `Status`='Zrealizowane' WHERE IDZ='" + id + "'";
			mysql_query(&mysql, query.c_str());
		}
		if (wybor == "4")
		{
			query = "UPDATE `zamowienie` SET `Status`='Anulowane' WHERE IDZ='" + id + "'";
			mysql_query(&mysql, query.c_str());
		}

	
}



void Zamowienie::Usun(MYSQL &mysql)
{
	string id;

	cout << "Numer zamowienia:";
	getline(cin, id);
	string query = "DELETE FROM `zamowienie` WHERE IDZ = " + id;
	mysql_query(&mysql, query.c_str());


}

void Zamowienie::WyswietlUser(MYSQL &mysql, string login)
{

	string query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE k.login = z.login and z.login = '" + login + "' and z.IDK = o.IDK";
	Wyswietl(mysql, query);
}

void Zamowienie::WyswietlUserN(MYSQL &mysql, string login)
{

	string query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE z.Status = 'Niepotwierdzone' and k.login = z.login and z.login = '" + login + "' and z.IDK = o.IDK";
	Wyswietl(mysql, query);
}

void Zamowienie::WyswietlOplacone(MYSQL &mysql)
{

	string query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE k.login = z.login and z.Status = 'Oplacone' and z.IDK = o.IDK ORDER BY z.Data, k.login";
	Wyswietl(mysql, query);
}


void Zamowienie::Znajdz(MYSQL &mysql)
{
	string query;
	string szukaj;
	cout << "Podaj nazwisko lub numer zamowienia:";
	getline(cin, szukaj);
	if (szukaj == "/all")
	{
		Wyswietl(mysql);
	}
	else
	{
		if (int(szukaj[0]) >= 48 && int(szukaj[0]) <= 57)
			query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE k.login = z. login and z.IDK = o.IDK and z.IDZ = " + szukaj;
		else
			query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE k.login = z. login and z.IDK = o.IDK and k.Nazwisko like '%" + szukaj + "%'";
		Wyswietl(mysql, query);
	}
}

void Zamowienie::Oplac(MYSQL &mysql, string login)
{
	string id;
	string wybor;
	string query;
	WyswietlUserN(mysql, login);
	vector <string> todo;

	double suma = 0;

	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	do
	{
	cout << endl << "Podaj id zamowien do oplacenia: " << endl;
	getline(cin, id);
	if (id != "")
	{
		//LAMBDAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAATUTAJ
		if (Sprawdz(mysql, login, id) && [](vector<string>d, string id)->bool {
				for (int i = 0; i < d.size(); i++)
				{
					if (d[i] == id) return false;
				}
			return true;
		}(todo, id)) todo.push_back(id);
		else cout << "Bledne id zamowienia" << endl;
		cout << endl << "Czy chcesz dodac nastepne? (Y/N): ";
		getline(cin, wybor);
	}
	} while (wybor == "Y" || wybor == "y");

	system("cls");
	cout << "	FAKTURA" << endl;
	cout << "##################################################################################################################" << endl;
	for (int i = 0; i < todo.size(); i++)
	{
		query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE k.login = z. login and z.IDK = o.IDK and z.login = '" + login + "' and z.IDZ = " + todo[i];
		Wyswietl(mysql, query);
		cout << endl;

		string query = "SELECT `Kwota` FROM `zamowienie` WHERE IDZ = " + todo[i];
		mysql_query(&mysql, query.c_str());

		idZapytania = mysql_store_result(&mysql);

		wiersz = mysql_fetch_row(idZapytania);
		double cena = stod(wiersz[0]);

		suma = suma + cena;
	}
	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "	RAZEM DO ZAPLATY: " << suma << endl<<endl;

	cout << "Zostaniesz przekierowany na strone zewnetrzna, czy kontynuowac? (Y/N): ";
	getline(cin, wybor);
	if (wybor == "Y" || wybor == "y")
	{
		cout << "Dokonywanie transakcji: ";
		for (int i = 0; i < 10; i++)
		{
			cout << ".";
			Sleep(500);
		}

		for (int i = 0; i < todo.size(); i++)
		{
			query = "UPDATE `zamowienie` SET `Status`= 'Oplacone' WHERE IDZ = " + todo[i];
			mysql_query(&mysql, query.c_str());
			query = "UPDATE `zamowienie` SET `Data`= SYSDATE() WHERE IDZ = " + todo[i];
			mysql_query(&mysql, query.c_str());
		}
		cout << endl << "Dziekujemy. Zamowienie zostanie zrealizowane natychmiast po otrzymaniu wplaty na konto" << endl;
		cin.ignore();
	}
}

void Zamowienie::Realizuj(MYSQL &mysql)
{
	string id;
	cout << endl << "Podaj numer zamowienia do zrealizowania" << endl;
	getline(cin, id);
	string query = "SELECT k.Nazwisko, k.Imie, k.Miasto, k.Adres, k.Telefon, k.Mail FROM `klienci`k, `zamowienie` z WHERE z.login = k.login and z.IDZ = " + id;
	Klient k;
	k.Wyswietl(mysql, query);
	cout << "Czy zrealizowano? (Y/N): ";
	string wybor;
	getline(cin, wybor);
	if (wybor == "Y" || wybor == "y")
	{
		query = "UPDATE `zamowienie` SET `Status`= 'Zrealizowane' WHERE IDZ = " + id;
		mysql_query(&mysql, query.c_str());
	}
}

bool Zamowienie::Sprawdz(MYSQL &mysql, string login, string id)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	string query = "SELECT z.IDZ, k.Nazwisko, o.IDK, o.Nazwa, z.Sztuk, z.Kwota, z.Data, z.Status FROM `zamowienie` z, `oferta` o, `klienci` k WHERE z.Status = 'Niepotwierdzone' and k.login = z. login and z.IDK= o.IDK and z.login = '" + login + "' and IDZ = " + id;

	mysql_query(&mysql, query.c_str());

	idZapytania = mysql_store_result(&mysql);

	if ((wiersz = mysql_fetch_row(idZapytania)) != NULL) return true;
	else return false;
}

void Zamowienie::ZyskM(MYSQL &mysql)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;
	string query;

	query = "SELECT ROUND(sum(Kwota),2) FROM `zamowienie` WHERE Status = 'Zrealizowane'";
	mysql_query(&mysql, query.c_str());
	idZapytania = mysql_store_result(&mysql);
	wiersz = mysql_fetch_row(idZapytania);
	if (wiersz[0] != NULL)
	{
		cout << "Zyski ogolnie: " << wiersz[0];
	}
	else cout << "Zyski ogolnie: " << 0;
	cout << endl;

	string wybor;
	cout << "Chcesz sprawdzic zyski firmy w konkretnym roku/miesiacu/dniu? (Y/N): ";
	getline(cin, wybor);
	if (wybor == "Y" || wybor == "y")
	{
		string data;
		cout << "Podaj date w formacie: RRRR-MM-DD" << endl;
		getline(cin, data);

		query = "SELECT ROUND(sum(Kwota),2) FROM `zamowienie` WHERE Status = 'Zrealizowane' and Data like '" + data + "%'";
		mysql_query(&mysql, query.c_str());
		idZapytania = mysql_store_result(&mysql);
		wiersz = mysql_fetch_row(idZapytania);
		if (wiersz[0] != NULL)
		{
			cout << "\tZyski " << data<<": " << wiersz[0] << " zl"<< endl;
		}
		else cout << "\tZyski " << data << ": " << 0 << " zl" << endl;
	}
	cin.ignore();
}

void Zamowienie::OfertyP(MYSQL &mysql)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;
	string query;

	cout << "Najczesciej zamawiane produkty                    Liczba" << endl<<endl;
	cout << "_________________________________________________________" << endl;
	query = "SELECT o.Nazwa, COUNT(z.IDZ) FROM `zamowienie` z, `oferta` o WHERE o.IDK = z.IDK GROUP BY z.IDK ORDER BY COUNT(z.IDZ) DESC";
	mysql_query(&mysql, query.c_str());
	idZapytania = mysql_store_result(&mysql);
	while ((wiersz = mysql_fetch_row(idZapytania)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idZapytania); i++)
		{
			cout.width(25);
			cout<<wiersz[i] << "  ";
			

		}
		cout << endl;
	}
	cin.ignore();

}