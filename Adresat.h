#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat {

public:
    Adresat();
    virtual ~Adresat();
    int pobierzIdUzytkownika();
    int pobierzIdAdresat();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

    void ustawIdUzytkownika(int id);
    void ustawIdAdresata(int id);
    void ustawImieAdresata(string imie);
    void ustawNazwiskoAdresata(string nazwisko);
    void ustawNumerTelefonu(string numer);
    void ustawEmail(string mail);
    void ustawAdres(string adres);

private:
    int idUzytkownik, idAdresat;
    string imieAdresat, nazwiskoAdresat, numerTelefonu, email, adres;
};

#endif // ADRESAT_H
