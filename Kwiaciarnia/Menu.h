#pragma once
#include "pch.h"

using namespace std;

class Menu
{
	string login;
	int indeks = 0;
public:
	Menu(string login);
	~Menu();
	string Check(int i);
	void AdminMenu(MYSQL &mysql);
	void UserMenu(MYSQL &mysql);
	void DodajUser(MYSQL &mysql);
	bool CzyAdmin();
	bool CzySukces();
	void MenuLogowania(MYSQL &mysql);
	string Logowanie(MYSQL &mysql);
	bool Walidacja(MYSQL &mysql, string login, string password);
	bool CzyHaslo(string password);
	void Oferty(MYSQL &mysql);
	void Zamowienia(MYSQL &mysql);
	void Klienci(MYSQL &mysql);
};

bool CzyLogin(string login, MYSQL mysql);
unsigned long hashe(unsigned char *str);
