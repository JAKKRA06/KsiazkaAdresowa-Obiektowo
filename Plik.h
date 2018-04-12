#ifndef PLIK_H
#define PLIK_H

#include <iostream>
#include <fstream>

using namespace std;

class Plik {

public:
    Plik();
    virtual ~Plik();
    friend class KsiazkaAdresowa;

protected:
    bool sprawdzCzyPlikJestPusty(fstream &plikTekstowy);
};

#endif // PLIK_H
