#pragma once
class Klient
{
public:
	Klient();
	~Klient();
	void Wyswietl(MYSQL &mysql);
	void Wyswietl(MYSQL &mysql, string query);
	void Usun(MYSQL &mysql);
	void Edytuj(MYSQL &mysql, string login);
	void Edytuj(MYSQL &mysql);
	void Znajdz(MYSQL &mysql);
};

 