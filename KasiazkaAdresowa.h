#ifndef KASIAZKAADRESOWA_H
#define KASIAZKAADRESOWA_H

#include "Adresat.h"
#include "PlikAdresaci.h"
#include "Uzytkownicy.h"

#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KsiazkaAdresowa {

private:
    vector<Adresat> adresaci;
    int idOstatniegoAdresataWPliku;
    int idZalogowanegoUzytkownika;
    PlikAdresaci plikAdresaci;
    Uzytkownicy uzytkownicy;
    Adresat adresat;

public:
    KsiazkaAdresowa(int idZalogowanegoUzytkownika);
    virtual ~KsiazkaAdresowa();
    void dodajAdresata();
    void edytujAdresata();
    void usunAdresata();
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void wyswietlWszystkichAdresatow();
    int pobierzIdDlaNowegoAdresataWPliku();
    int pobierzIdDlaZalogowanegoUzytkownika();
    int pobierzIdOstatniegoAdresataWPliku();

private:
    char menuEdycjiAdresata(int numerAdresataDoEdycji);
    void panelEdycjiAdresata(char wyborUzytkownika, int numerAdresataDoEdycji);
    void aktualizaujDaneEdytowanegoAdresata(Adresat adresat, int idAdresat);
    string zmienDaneAdresataNaLiniezDanymiOddzielonePionowaKreska(Adresat adresat);
    string konwersjaIntNaString(Adresat adresat);
    string konwersjaIntNaStringDruga(Adresat adresat);
    void edytujWybranaLinieWPliku(int numerLiniiEdytowanegoAdresata, string liniaZNowymiDanymi);
    void aktualizujDanePoUsunieciuAdresata(int numerAdresataDoUsuniecia);
    int zwrocNumerLiniiWKtorejJestAdresat(int idEdytowanegoAdresata);
    int rozdzielWczytanaLinie(string wczytanaLinia, char znak);
};

#endif // KASIAZKAADRESOWA_H
