#include "PlikUzytkownicy.h"

using namespace std;

PlikUzytkownicy::PlikUzytkownicy() {

    this->nazwaPlikuZUzytkownikami = "Uzytkownicy.txt";
}

PlikUzytkownicy::~PlikUzytkownicy() {;}

vector<Uzytkownik> PlikUzytkownicy::rozdzielanieStringowUzytkownicy(vector<Uzytkownik> &uzytkownicy, string wczytanaLinia, char znak) {

    int numerPojedynczejDanej = 1;
    stringstream ss(wczytanaLinia);
    string pojedynczaDana = "";

    while(getline(ss, pojedynczaDana, znak)) {

        switch(numerPojedynczejDanej) {
        case 1:
            uzytkownik.ustawId(atoi(pojedynczaDana.c_str())) ;
            break;
        case 2:
            uzytkownik.ustawNazwe(pojedynczaDana);
            break;
        case 3:
            uzytkownik.ustawHaslo(pojedynczaDana);
            break;
        }
        numerPojedynczejDanej++;
        pojedynczaDana = "";
    }
    uzytkownicy.push_back(uzytkownik);
    return uzytkownicy;
}

void PlikUzytkownicy::wczytajPlikUzytkownicy(vector<Uzytkownik> &uzytkownicy) {

    string wczytanaLinia = "";
    fstream plik;

    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios::in);

    if(plik.good() == true) {

        while(getline(plik, wczytanaLinia)) {

            uzytkownicy = rozdzielanieStringowUzytkownicy(uzytkownicy, wczytanaLinia, '|');
        }
    }
    plik.close();
}

void PlikUzytkownicy::zapiszPlikUzytkownicy(vector<Uzytkownik> &uzytkownicy) {

    fstream plik;
    Uzytkownik uzytkownik;
    vector<Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios::out);

    if(plik.good() == true) {

        for(vector<Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {

            if(itr == itrKoniec)
                plik << itr -> Uzytkownik::pobierzId() << "|" << itr -> Uzytkownik::pobierzNazwe() << "|" << itr -> Uzytkownik::pobierzHaslo() << "|";
            else
                plik << itr -> Uzytkownik::pobierzId() << "|" << itr -> Uzytkownik::pobierzNazwe() << "|" << itr -> Uzytkownik::pobierzHaslo() << "|" << endl;
        }
        plik.close();
    } else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << endl;
}

void PlikUzytkownicy::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {

    fstream plik;
    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios::out | ios::app);

    if(plik.good() == true) {

        if(sprawdzCzyPlikJestPusty(plik) == true) {

            plik << uzytkownik.pobierzId() << "|" << uzytkownik.pobierzNazwe() << "|" << uzytkownik.pobierzHaslo() << "|";
        } else
            plik << endl << uzytkownik.pobierzId() << "|" << uzytkownik.pobierzNazwe() << "|" << uzytkownik.pobierzHaslo() << "|";

        plik.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac zmian" << endl;
}
