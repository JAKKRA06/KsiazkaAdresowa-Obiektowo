#include "Plik.h"

using namespace std;

Plik::Plik() {;}

Plik::~Plik() {;}

bool Plik::sprawdzCzyPlikJestPusty(fstream &plikTekstowy) {

    plikTekstowy.seekg(0, ios::end);

    if (plikTekstowy.tellg() == 0)
        return true;
     else
        return false;
}

