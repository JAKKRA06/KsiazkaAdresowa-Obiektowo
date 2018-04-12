#include "Uzytkownicy.h"

using namespace std;

int Uzytkownicy::pobierzIdDlaNowegoUzytkownika() {

    if(uzytkownicy.empty() == true) {
        return 1;
    } else
        return uzytkownicy.back().pobierzId() + 1;
}

void Uzytkownicy::rejestracja() {

    string nazwa = "", haslo = "";
    vector<Uzytkownik>::iterator itr = uzytkownicy.begin();

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;

    while(itr != uzytkownicy.end()) {

        if(itr -> Uzytkownik::pobierzNazwe() == nazwa) {

            cout << "Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> nazwa;
            itr = uzytkownicy.begin();
        }
        else {
            itr++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> haslo;

    uzytkownik.ustawNazwe(nazwa);
    uzytkownik.ustawHaslo(haslo);
    uzytkownik.ustawId(pobierzIdDlaNowegoUzytkownika());

    plikUzytkownicy.dopiszUzytkownikaDoPliku(uzytkownik);
    uzytkownicy.push_back(uzytkownik);

    cout << "Uzytkownik zostal dodany" << endl;
    Sleep(2000);
}

int Uzytkownicy::pobierzIdZalogowanegoUzytkownika() {

    return idZalogowanegoUzytkownika;
}

Uzytkownicy::Uzytkownicy() {

    this->idZalogowanegoUzytkownika = 0;
    plikUzytkownicy.wczytajPlikUzytkownicy(uzytkownicy);
}

Uzytkownicy::~Uzytkownicy() {

    uzytkownicy.clear();
}

void Uzytkownicy::logowanie() {

    string nazwa = "";
    string haslo = "";
    bool czyIstniejeUzytkownik = false;

    if(uzytkownicy.empty() == true) {

        cout << "Brak zarejestrowanych uzytkownikow. Przejdz do rejestracji" << endl;
        system("pause");
        return;
    }

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    cin.ignore();

    vector<Uzytkownik>::iterator itr = uzytkownicy.begin();

    while(itr != uzytkownicy.end()) {

        if(itr -> Uzytkownik::pobierzNazwe() == nazwa) {

            for(int ilosc = 0; ilosc < 3; ilosc++) {

                cout << "Podaj haslo. Pozostalo " << 3 - ilosc << " prob: ";
                cin >> haslo;

                if(itr -> Uzytkownik::pobierzHaslo() == haslo) {

                    this->idZalogowanegoUzytkownika = itr -> Uzytkownik::pobierzId();

                    cout << "Zalogowales sie jako " << itr -> Uzytkownik::pobierzNazwe() << endl;
                    Sleep(1500);
                    return;
                }
            }
            cout << "Podales 3 razy bledne haslo" << endl;
            Sleep(1500);
            return;
        }
        else
            itr++;
    }
    if (czyIstniejeUzytkownik == false)
        cout << endl << "Nie ma uzytkownika z takim loginem" << endl << endl;

    system("pause");
}

void Uzytkownicy::wyloguj() {

    this->idZalogowanegoUzytkownika = 0;
}

void Uzytkownicy::zmianaHasla() {

    system("cls");
    bool czyZmienionoHaslo = false;
    vector<Uzytkownik>::iterator itr = uzytkownicy.begin();

    while(itr != uzytkownicy.end()) {

        if(itr -> Uzytkownik::pobierzId() == idZalogowanegoUzytkownika) {

            cout << "       ZALOGOWANY UZYTKOWNIK : " << itr -> Uzytkownik::pobierzNazwe() << endl;
            break;
        }
        itr++;
    }

    string haslo = "";
    cout << endl;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;

    for(itr; itr != uzytkownicy.end(); itr++)    {

        if(itr -> Uzytkownik::pobierzId() == idZalogowanegoUzytkownika) {

            itr -> Uzytkownik::ustawHaslo(haslo);

            czyZmienionoHaslo = true;
        }
    }
    plikUzytkownicy.zapiszPlikUzytkownicy(uzytkownicy);

    if (czyZmienionoHaslo) {
        cout << "Haslo zostalo zmienione." << endl << endl;
    } else {
        cout << "Haslo NIE zostalo zmienione." << endl << endl;
    }
    system("pause");
}
