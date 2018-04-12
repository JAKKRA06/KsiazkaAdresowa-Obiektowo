#ifndef PLIKADRESACI_H
#define PLIKADRESACI_H

#include "Plik.h"
#include "Adresat.h"
#include "Uzytkownicy.h"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class PlikAdresaci :public Plik {

public:
    PlikAdresaci();
    virtual ~PlikAdresaci();
    int wczytajPlikAdresaci(vector<Adresat> &adresaci, int idzalogowanego);

private:
    string nazwaPlikuZAdresatami;
    void pobierzIdOstatniegoAdresataWPliku();
    string pobierzNazwePlikuZAdresatami();
    vector<Adresat> rozdzielanieStringowAdresaci(vector<Adresat> &adresaci, string wczytanaLinia, char znak, int idzalogowanego);
    int pobierzIDOstatniegoAdresataWPliku(string daneOstatniegoAdresataWPliku, char znak);

};

#endif // PLIKADRESACI_H
