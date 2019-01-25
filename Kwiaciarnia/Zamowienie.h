#pragma once
class Zamowienie
{
public:
	Zamowienie();
	~Zamowienie();
	void Wyswietl(MYSQL &mysql, string query = "0");
	void Dodaj(MYSQL &mysql, string login);
	void Usun(MYSQL &mysql);
	void Edytuj(MYSQL &mysql);
	void Znajdz(MYSQL &mysql);
	void WyswietlUser(MYSQL &mysql, string login);
	void WyswietlUserN(MYSQL &mysql, string login);
	void WyswietlOplacone(MYSQL &mysql);
	void Oplac(MYSQL &mysql, string login);
	void Realizuj(MYSQL &mysql);
	bool Sprawdz(MYSQL &mysql, string login, string id);
	void ZyskM(MYSQL &mysql);
	void OfertyP(MYSQL &mysql);
};

