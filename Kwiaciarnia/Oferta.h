#pragma once
class Oferta
{
public:
	Oferta();
	~Oferta();
	void Wyswietl(MYSQL &mysql, string query = "0");
	void Dodaj(MYSQL &mysql);
	void Usun(MYSQL &mysql);
	void Edytuj(MYSQL &mysql);
	void Znajdz(MYSQL &mysql);
};

