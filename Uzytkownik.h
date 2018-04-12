#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik {

private:
    string nazwa;
    string haslo;
    int id;

public:
    Uzytkownik();
    virtual ~Uzytkownik();

    void ustawNazwe(string nazwe);
    void ustawHaslo(string haslo);
    void ustawId(int id);

    string pobierzNazwe();
    string pobierzHaslo();
    int pobierzId();

};

#endif // UZYTKOWNIK_H
