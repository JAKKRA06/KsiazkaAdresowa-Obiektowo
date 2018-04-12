#include "Uzytkownicy.h"
#include "KasiazkaAdresowa.h"

#include <iostream>


using namespace std;

char wybierzOpcjeZMenuGlownego() {

    system("cls");
    char wyborUzytkownika;
    cout << "----- MENU GLOWNE -----" << endl;
    cout << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Zamknij programu" << endl;

    cin >> wyborUzytkownika;
    return wyborUzytkownika;
}

char wybierzOpcjeZMenuUzytkownika() {

    system("cls");
    char wybor;

    cout << "-------- MENU UZYTKOWNIKA --------" << endl;
    cout << endl;
    cout << "1. Dodaj nowy kontakt" << endl;
    cout << "2. Wyszukiwanie adresata po imieniu" << endl;
    cout << "3. Wyszukiwanie adresata po nazwisku" << endl;
    cout << "4. Wyswietl wszystkich adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edycja adresata" << endl;
    cout << "7. Zmiana hasla" << endl;
    cout << "8. Wylogowanie" << endl;
    cin >> wybor;
    return wybor;
}

int main() {

    Uzytkownicy uzytkownicy;
    char wybor;

    while(true) {

        if(uzytkownicy.pobierzIdZalogowanegoUzytkownika() == 0) {

            wybor = wybierzOpcjeZMenuGlownego();

            switch(wybor) {
            case '1':
                uzytkownicy.rejestracja();
                break;
            case '2':
                uzytkownicy.logowanie();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << "Nie ma takiej opcji w menu" << endl;
                system("pause");
            }
        }
        else if (uzytkownicy.pobierzIdZalogowanegoUzytkownika() > 0) {

            do {
                KsiazkaAdresowa adresaci(uzytkownicy.pobierzIdZalogowanegoUzytkownika());
                wybor = wybierzOpcjeZMenuUzytkownika();

                switch(wybor) {

                case '1':
                     adresaci.dodajAdresata();
                    break;
                case '2':
                    adresaci.wyszukajAdresataPoImieniu();
                    break;
                case '3':
                    adresaci.wyszukajAdresataPoNazwisku();
                    break;
                case '4':
                    adresaci.wyswietlWszystkichAdresatow();
                    break;
                case '5':
                    adresaci.usunAdresata();
                    break;
                case '6':
                     adresaci.edytujAdresata();
                    break;
                case '7':
                    uzytkownicy.zmianaHasla();
                    break;
                case '8':
                    uzytkownicy.wyloguj();
                    break;
                }
            } while(wybor != '8');
        }
    }
    return 0;
}
