#include "Adresat.h"

#include <iostream>

using namespace std;

Adresat::Adresat()
{
    idUzytkownik = 0;
    idAdresat = 0;
    imieAdresat = "";
    nazwiskoAdresat = "";
    numerTelefonu = "";
    email = "";
    adres = "";
}

Adresat::~Adresat(){;}

void Adresat::ustawIdUzytkownika(int id)
{
    this->idUzytkownik = id;
}

void Adresat::ustawIdAdresata(int id)
{
    this->idAdresat = id;
}

void Adresat::ustawImieAdresata(string imie)
{
    this->imieAdresat = imie;
}

void Adresat::ustawNazwiskoAdresata(string nazwisko)
{
    this->nazwiskoAdresat = nazwisko;
}

void Adresat::ustawNumerTelefonu(string nrTel)
{
    this->numerTelefonu = nrTel;
}

void Adresat::ustawEmail(string mail)
{
    this->email = mail;
}

void Adresat::ustawAdres(string adr)
{
    this->adres = adr;
}


int Adresat::pobierzIdUzytkownika()
{
    return idUzytkownik;
}

int Adresat::pobierzIdAdresat()
{
    return idAdresat;
}

string Adresat::pobierzImie()
{
    return imieAdresat;
}

string Adresat::pobierzNazwisko()
{
    return nazwiskoAdresat;
}

string Adresat::pobierzNumerTelefonu()
{
    return numerTelefonu;
}

string Adresat::pobierzEmail()
{
    return email;
}

string Adresat::pobierzAdres()
{
    return adres;
}
