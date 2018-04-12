#include "Uzytkownik.h"

using namespace std;

Uzytkownik::Uzytkownik()
{
    id = 0;
    nazwa = "";
    haslo = "";
}

Uzytkownik::~Uzytkownik(){;}

void Uzytkownik::ustawNazwe(string nazwa) {

    this->nazwa = nazwa;
}

void Uzytkownik::ustawHaslo(string haslo) {

    this->haslo = haslo;
}

void Uzytkownik::ustawId(int id) {

    this->id = id;
}


string Uzytkownik::pobierzNazwe() {

    return nazwa;
}

string Uzytkownik::pobierzHaslo() {

    return haslo;
}

int Uzytkownik::pobierzId() {

    return id;
}
