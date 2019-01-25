#include "pch.h"
#include "Menu.h"

Oferta o;
Zamowienie z;
Klient k;

Menu::Menu(string login)
{
	indeks = 0;
	this->login = login;
	
}



Menu::~Menu()
{
}

bool Menu::CzyAdmin()
{
	if (login == "admin") return true;
	else return false;
}

bool Menu::CzySukces()
{
	if (login == "") return false;
	else return true;
}

string Menu::Check(int i)
{
	if (indeks == i) return " X ";
	else return " ";
}

void Menu::AdminMenu(MYSQL &mysql)
{
	char c;
	indeks = 0;
	do
	{
		system("CLS");
		cout << "[" << Check(0) << "]. Zamowienia" << endl;
		cout << "[" << Check(1) << "]. Oferty" << endl;
		cout << "[" << Check(2) << "]. Klienci" << endl;
		cout << "[" << Check(3) << "]. Bilans firmy" << endl;
		cout << "[" << Check(4) << "]. Wyjscie" << endl;

		c = _getch();
		switch (c)
		{
		case 80:
		{
			indeks = (indeks < 4) ? indeks + 1 : indeks;
			break;
		}
		case 72:
		{
			indeks = (indeks > 0) ? indeks - 1 : indeks;

			break;
		}

		case 13:
		{
			system("CLS");

			switch (indeks)
			{
			case 0:
			{
				Zamowienia(mysql);
				break;

			}
			case 1:
			{
				Oferty(mysql);
				break;

			}
			case 2:
			{
				Klienci(mysql);
				break;

			}

			case 3:
			{
				z.ZyskM(mysql);
				break;

			}

			case 4:
			{
				exit(0);
			}

			case 5:
			{


			}


			break;
			}
		}
		}
	} while (c != 27);
}

void Menu::Oferty(MYSQL &mysql)
{
	char c;
	indeks = 0;
	do
	{
		system("CLS");
		cout << "[" << Check(0) << "]. Wyswietl oferty" << endl;
		cout << "[" << Check(1) << "]. Dodaj oferte" << endl;
		cout << "[" << Check(2) << "]. Usun oferte" << endl;
		cout << "[" << Check(3) << "]. Edytuj oferte" << endl;
		cout << "[" << Check(4) << "]. Wyszukaj oferte" << endl;

		c = _getch();
		switch (c)
		{
		case 80:
		{
			indeks = (indeks < 4) ? indeks + 1 : indeks;
			break;
		}
		case 72:
		{
			indeks = (indeks > 0) ? indeks - 1 : indeks;

			break;
		}

		case 13:
		{
			system("CLS");

			switch (indeks)
			{
			case 0:
			{
				o.Wyswietl(mysql);
				cin.ignore();
				break;

			}
			case 1:
			{
				o.Dodaj(mysql);
				cin.ignore();
				break;

			}
			case 2:
			{
				o.Usun(mysql);
				cin.ignore();
				break;

			}

			case 3:
			{
				o.Edytuj(mysql);
				break;

			}
			case 4:
			{
				o.Znajdz(mysql);
				cin.ignore();


				break;

			}


			}


			break;
		}

		}
	} while (c != 27);
}

void Menu::Klienci(MYSQL &mysql)
{
	char c;
	indeks = 0;
	do
	{
		system("CLS");
		cout << "[" << Check(0) << "]. Wyswietl klientow" << endl;
		cout << "[" << Check(1) << "]. Dodaj klienta" << endl;
		cout << "[" << Check(2) << "]. Usun klienta" << endl;
		cout << "[" << Check(3) << "]. Edytuj dane kliena" << endl;
		cout << "[" << Check(4) << "]. Wyszukaj klienta" << endl;

		c = _getch();
		switch (c)
		{
		case 80:
		{
			indeks = (indeks < 4) ? indeks + 1 : indeks;
			break;
		}
		case 72:
		{
			indeks = (indeks > 0) ? indeks - 1 : indeks;

			break;
		}

		case 13:
		{
			system("CLS");

			switch (indeks)
			{
			case 0:
			{
				k.Wyswietl(mysql);
				cin.ignore();
				break;

			}
			case 1:
			{
				DodajUser(mysql);
				cin.ignore();
				break;

			}
			case 2:
			{
				k.Usun(mysql);
				cin.ignore();
				break;

			}

			case 3:
			{
				k.Edytuj(mysql);
				break;

			}
			case 4:
			{
				k.Znajdz(mysql);
				cin.ignore();


				break;

			}


			}


			break;
		}

		}
	} while (c != 27);
}


void Menu::Zamowienia(MYSQL &mysql)
{
	char c;
	indeks = 0;
	do
	{
		system("CLS");
		cout << "[" << Check(0) << "]. Wyswietl zamowienia" << endl;
		cout << "[" << Check(1) << "]. Dodaj zamowienie" << endl;
		cout << "[" << Check(2) << "]. Usun zamowienie" << endl;
		cout << "[" << Check(3) << "]. Edytuj zamowienie" << endl;
		cout << "[" << Check(4) << "]. Wyszukaj zamowienie" << endl;
		cout << "[" << Check(5) << "]. Wyswietl zamowienia do potwierdzenia" << endl;

		c = _getch();
		switch (c)
		{
		case 80:
		{
			indeks = (indeks < 5) ? indeks + 1 : indeks;
			break;
		}
		case 72:
		{
			indeks = (indeks > 0) ? indeks - 1 : indeks;

			break;
		}

		case 13:
		{
			system("CLS");

			switch (indeks)
			{
			case 0:
			{
				z.Wyswietl(mysql);
				cin.ignore();
				break;

			}
			case 1:
			{
				z.Dodaj(mysql, login);
				cin.ignore();
				break;

			}
			case 2:
			{
				z.Usun(mysql);
				cin.ignore();
				break;

			}

			case 3:
			{
				z.Edytuj(mysql);
				break;

			}
			case 4:
			{
				z.Znajdz(mysql);
				cin.ignore();
				break;
			}
			case 5:
			{
				z.WyswietlOplacone(mysql);
				z.Realizuj(mysql);
				break;

			}


			}


			break;
		}

		}
	} while (c != 27);
}

void Menu::UserMenu(MYSQL &mysql)
{
	char c;
	indeks = 0;
	do
	{
		system("CLS");
		cout << "Zalogowano na: " << login << endl;
		cout << "[" << Check(0) << "]. Sprawdz oferty sklepu" << endl;
		cout << "[" << Check(1) << "]. Zloz zamowienie" << endl;
		cout << "[" << Check(2) << "]. Sprawdz swoje zamowienia" << endl;
		cout << "[" << Check(3) << "]. Zaplac za zamowienie" << endl;
		cout << "[" << Check(4) << "]. Edytuj dane kontaktowe/do wysylki" << endl;
		cout << "[" << Check(5) << "]. Zobacz najchetniej kupowane" << endl;

		c = _getch();
		switch (c)
		{
		case 80:
		{
			indeks = (indeks < 6) ? indeks + 1 : indeks;
			break;
		}
		case 72:
		{
			indeks = (indeks > 0) ? indeks - 1 : indeks;

			break;
		}

		case 13:
		{
			system("CLS");

			switch (indeks)
			{
			case 0:
			{
				o.Wyswietl(mysql);
				string wybor;
				do
				{
					cout << endl << "Chcesz wyszukac oferte? (Y/N)";
					getline(cin, wybor);
					if(wybor != "N" && wybor != "n") o.Znajdz(mysql);
				} while (wybor != "N" && wybor != "n");

				break;

			}
			case 1:
			{
				string wybor;
				do
				{
					o.Znajdz(mysql);
					cout << endl <<"Chcesz przegladac dalej? (Y/N)";
					getline(cin, wybor);
				} while (wybor != "N" && wybor != "n");

				cout << "Chcesz zlozyc zamowienie? (Y/N)";
				getline(cin, wybor);
				if(wybor == "Y" || wybor == "y")
				z.Dodaj(mysql, login);
				break;

			}
			case 2:
			{
				z.WyswietlUser(mysql, login);
				cin.ignore();
				break;

			}

			case 3:
			{
				z.Oplac(mysql, login);
				break;

			}

			case 4:
			{
				k.Edytuj(mysql, login);
				break;
			}

			case 5:
			{
				z.OfertyP(mysql);
				cin.ignore();
				break;
			}

			case 6:
			{
				exit(0);
			}


			}


			break;
		}

		}

	} while (c != 27);
}

bool CzyLogin(string login, MYSQL mysql)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	string query = "SELECT * FROM users WHERE login = '" + login + "'";

	mysql_query(&mysql, query.c_str());

	idZapytania = mysql_store_result(&mysql);

	if ((wiersz = mysql_fetch_row(idZapytania)) != NULL)	return false;
	else return true;
}

bool Menu::CzyHaslo(string password)
{
	if (password.length() >= 8)
	{
		int cyfry = 0;
		for (int i = 0; i < password.length(); i++)
		{
			if (int(password[i]) >= 48 && int(password[i]) <= 57) cyfry++;
		}
		if (cyfry >= 3) return true;
		else
		{
			cout << "Co najmniej 3 cyfry" << endl;
			return false;
		}
	}
	else
	{
		cout << "Co najmniej 8 znakow" << endl;
		return false;
	}
}

void Menu::DodajUser(MYSQL &mysql)
{

	string login;
	string nazwisko;
	string imie;
	string adres;
	string miasto;
	string password;


	cout << "Podaj login (bedzie sluzyl jako twoj identyfikator) ";
	getline(cin, login);
	if (CzyLogin(login, mysql))
	{
		do
		{
			cout << "Podaj haslo: ";
			getline(cin, password);


		} while (!CzyHaslo(password));
		unsigned char cstr[30];
		strcpy((char*)cstr, password.c_str());
		unsigned long password_l = hashe(cstr);
		password = to_string(password_l);
		
		cout << endl << "	Wypelnij dane: " << endl;
			cout << "Nazwisko: ";
			getline(cin, nazwisko);
			cout << "Imie: ";
			getline(cin, imie);
			cout << "Miasto: ";
			getline(cin, miasto);
			cout << "Adres: ";
			getline(cin, adres);

			
			string query = "INSERT INTO `users`(`login`, `password`) VALUES('" + login + "', '" + password + "')";
			mysql_query(&mysql, query.c_str());
			query = "INSERT INTO `klienci`(`login`, `Nazwisko`, `Imie`, `Miasto`, `Adres`) VALUES('" + login + "', '" + nazwisko + "', '" + imie + "', '" + miasto + "', '" + adres + "')";
			mysql_query(&mysql, query.c_str());
			cout << "Pomyslnie zarejestrowano" << endl;
		
		
		
	}
	else
	{
		cout << "Login zajety. Wybierz inny login" << endl;
	}
}



bool Menu::Walidacja(MYSQL &mysql, string login, string password)
{
	MYSQL_RES *idZapytania;
	MYSQL_ROW  wiersz;

	string query = "SELECT * FROM users WHERE login='" + login + "' and password='" + password + "'";


	mysql_query(&mysql, query.c_str());

	idZapytania = mysql_store_result(&mysql);

	if ((wiersz = mysql_fetch_row(idZapytania)) != NULL)	return true;
	else return false;
}

string Menu::Logowanie(MYSQL &mysql)
{
	string login;
	string password;

	system("CLS");
	cout << "Podaj login: ";
	getline(cin, login);
	cout << "Podaj haslo: ";
	getline(cin, password);
	unsigned char cstr[30];
	strcpy((char*)cstr, password.c_str());
	unsigned long password_l = hashe(cstr);
	password = to_string(password_l);

	if (!Walidacja(mysql, login, password)) {
		cout << "Bledne dane logowania" << endl;
		Sleep(1000);
		return "";
	}
	else return login;
}

void Menu::MenuLogowania(MYSQL &mysql)
{
	char c;
	indeks = 0;
	do
	{

		system("CLS");
		cout << " *******************************************************" << endl;
		cout << " *                                                     *" << endl;
		cout << " *                       Kwiaciarnia                   *" << endl;
		cout << " *                                                     *" << endl;
		cout << " *******************************************************" << endl << endl;
		cout << "[" << Check(0) << "]. Zaloguj sie" << endl;
		cout << "[" << Check(1) << "]. Zarejestruj sie" << endl;
		cout << "[" << Check(2) << "]. Wyjscie" << endl << endl << endl;
		system("DATE /T");

		c = _getch();
		switch (c)
		{
		case 80:
		{
			indeks = (indeks < 2) ? indeks + 1 : indeks;
			break;
		}
		case 72:
		{
			indeks = (indeks > 0) ? indeks - 1 : indeks;

			break;
		}

		case 13:
		{
			system("CLS");

			switch (indeks)
			{
			case 0:
			{
				Menu menu(Logowanie(mysql));
				if (menu.CzyAdmin())
					menu.AdminMenu(mysql);
				else if (menu.CzySukces())
					menu.UserMenu(mysql);
				break;

			}
			case 1:
			{
				DodajUser(mysql);
				Sleep(1000);
				break;

			}
			case 2:
			{
				exit(0);
				break;

			}

			case 3:
			{

				break;

			}

			case 4:
			{
				exit(0);
			}



			}


			break;
		}

		}

	} while (c != 27);
}

unsigned long hashe(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;

	return hash;
}