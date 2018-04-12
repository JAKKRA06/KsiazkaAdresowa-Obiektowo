#ifndef PLIKUZYTKOWNICY_H
#define PLIKUZYTKOWNICY_H

#include "Uzytkownik.h"
#include "Plik.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

using namespace std;


class PlikUzytkownicy :private Plik {

private:
    string nazwaPlikuZUzytkownikami;
    Uzytkownik uzytkownik;

public:
    PlikUzytkownicy();
    virtual ~PlikUzytkownicy();
    void wczytajPlikUzytkownicy(vector<Uzytkownik> &uzytkownicy);
    void zapiszPlikUzytkownicy(vector<Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);

private:
    vector<Uzytkownik> rozdzielanieStringowUzytkownicy(vector<Uzytkownik> &uzytkownicy, string wczytanaLinia, char znak);

};

#endif // PLIKUZYTKOWNICY_H
