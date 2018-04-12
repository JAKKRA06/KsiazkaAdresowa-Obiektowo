#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <vector>
#include <cstdlib>
#include <windows.h>
#include "Uzytkownik.h"
#include <iostream>
#include <PlikUzytkownicy.h>


using namespace std;

class Uzytkownicy {
private:
    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    PlikUzytkownicy plikUzytkownicy;
    Uzytkownik uzytkownik;

public:
    Uzytkownicy();
    virtual ~Uzytkownicy();

    void rejestracja();//done
    void logowanie();//done
    void zmianaHasla();//do spr
    void wyloguj();// done
    int pobierzIdZalogowanegoUzytkownika();
    int pobierzIdDlaNowegoUzytkownika();
};
#endif // UZYTKOWNICY_H
