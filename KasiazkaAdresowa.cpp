#include "KasiazkaAdresowa.h"

using namespace std;

KsiazkaAdresowa::KsiazkaAdresowa(int idZalogowanegoUzytkownika) {

    this->idZalogowanegoUzytkownika = idZalogowanegoUzytkownika;
    this->idOstatniegoAdresataWPliku = plikAdresaci.wczytajPlikAdresaci(adresaci, idZalogowanegoUzytkownika);
}

KsiazkaAdresowa::~KsiazkaAdresowa() {

    adresaci.clear();
}

int KsiazkaAdresowa::pobierzIdDlaNowegoAdresataWPliku() {

    if(adresaci.empty() == true) {
        return 1;
    } else
        return idOstatniegoAdresataWPliku + 1;
}

int KsiazkaAdresowa::pobierzIdOstatniegoAdresataWPliku() {

    return idOstatniegoAdresataWPliku + 1;
}

int KsiazkaAdresowa::pobierzIdDlaZalogowanegoUzytkownika() {

    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::dodajAdresata() {

    system("cls");
    string  imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";

    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, numerTelefonu);
    cout << "Podaj email: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    adresat.ustawIdAdresata(pobierzIdOstatniegoAdresataWPliku());
    adresat.ustawIdUzytkownika(pobierzIdDlaZalogowanegoUzytkownika());
    adresat.ustawImieAdresata(imie);
    adresat.ustawNazwiskoAdresata(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    adresaci.push_back(adresat);

    fstream plikDozapisu;
    plikDozapisu.open("Adresaci.txt", ios::out | ios::app);
    if(plikDozapisu.good()) {

        if(plikAdresaci.sprawdzCzyPlikJestPusty(plikDozapisu) == true) {

            plikDozapisu << adresat.pobierzIdAdresat() << "|" << pobierzIdDlaZalogowanegoUzytkownika() << "|" << adresat.pobierzImie() << "|" << adresat.pobierzNazwisko() << "|" << adresat.pobierzNumerTelefonu() << "|" << adresat.pobierzEmail() << "|" << adresat.pobierzAdres() << "|";
        } else {

            plikDozapisu << endl << adresat.pobierzIdAdresat() << "|" << pobierzIdDlaZalogowanegoUzytkownika() << "|" << adresat.pobierzImie() << "|" << adresat.pobierzNazwisko() << "|" << adresat.pobierzNumerTelefonu() << "|" << adresat.pobierzEmail() << "|" << adresat.pobierzAdres() << "|";
        }
        plikDozapisu.close();

        cout << endl;

        cout << "Adresat zostal dodany do listy kontaktow" << endl;
        Sleep(2000);
        return;
    } else
        cout << "Nie mozna otworzyc pliku" << endl;
}

void KsiazkaAdresowa::wyszukajAdresataPoImieniu() {

    system("cls");

    string imie = "";
    int iloscOsob = 0;
    vector<Adresat>::iterator itr = adresaci.begin();

    cout << "Wpisz imie adresata, ktorego chcesz wyszukac: ";
    cin >> imie;

    for(itr; itr != adresaci.end(); itr++) {

        if(itr -> Adresat::pobierzIdUzytkownika() == pobierzIdDlaZalogowanegoUzytkownika()) {

            if(itr -> Adresat::pobierzImie() == imie) {

                cout << "Id:                 " << itr -> Adresat::pobierzIdAdresat() << endl;
                cout << "IdUzytkownik:       " << itr -> Adresat::pobierzIdUzytkownika() << endl;
                cout << "Imie:               " << itr -> Adresat::pobierzImie() << endl;
                cout << "Nazwisko:           " << itr -> Adresat::pobierzNazwisko() << endl;
                cout << "Numer Telefonu:     " << itr -> Adresat::pobierzNumerTelefonu() << endl;
                cout << "Email:              " << itr -> Adresat::pobierzEmail() << endl;
                cout << "Adres:              " << itr -> Adresat::pobierzAdres() << endl;
                cout << "-------------------------" << endl;
                iloscOsob++;
            }
        }
    }

    if(iloscOsob == 0) {
        cout << "Kontakt o imieniu " << imie << " nie wystepuje w ksiazce adresowej" << endl;
    }
    cout << endl;

    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
    getch();
}

void KsiazkaAdresowa::wyszukajAdresataPoNazwisku() {

    system("cls");

    string nazwisko = "";
    int iloscOsob = 0;
    vector<Adresat>::iterator itr = adresaci.begin();

    cout << "Wpisz nazwisko adresata, ktorego chcesz wyszukac: ";
    cin >> nazwisko;

    for(itr; itr != adresaci.end(); itr++) {

        if(itr -> Adresat::pobierzIdUzytkownika() == pobierzIdDlaZalogowanegoUzytkownika()) {

            if(itr -> Adresat::pobierzNazwisko() == nazwisko) {

                cout << "Id:                 " << itr -> Adresat::pobierzIdAdresat() << endl;
                cout << "IdUzytkownik:       " << itr -> Adresat::pobierzIdUzytkownika() << endl;
                cout << "Imie:               " << itr -> Adresat::pobierzImie() << endl;
                cout << "Nazwisko:           " << itr -> Adresat::pobierzNazwisko() << endl;
                cout << "Numer Telefonu:     " << itr -> Adresat::pobierzNumerTelefonu() << endl;
                cout << "Email:              " << itr -> Adresat::pobierzEmail() << endl;
                cout << "Adres:              " << itr -> Adresat::pobierzAdres() << endl;
                cout << "-------------------------" << endl;
                iloscOsob++;
            }
        }
    }

    if(iloscOsob == 0) {
        cout << "Kontakt o nazwisku " << nazwisko << " nie wystepuje w ksiazce adresowej" << endl;
    }
    cout << endl;

    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
    getch();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {

    system("cls");

    char wyborUzytkownika;
    int iloscOsob = 0;
    vector<Adresat>::iterator itr = adresaci.begin();

    if(adresaci.empty() == true) {

        cout << "Brak wpisow w ksiazce adresowej" << endl;
        cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz " << endl;
        getch();

    } else {
        cout << "-----Spis kontaktow w ksiazce adresowej-----" << endl;

        for(itr; itr != adresaci.end(); itr++) {

            if(itr -> Adresat::pobierzIdUzytkownika() == idZalogowanegoUzytkownika) {

                cout << "Id:                 " << itr -> Adresat::pobierzIdAdresat() << endl;
                cout << "IdUzytkownik:       " << itr -> Adresat::pobierzIdUzytkownika() << endl;
                cout << "Imie:               " << itr -> Adresat::pobierzImie() << endl;
                cout << "Nazwisko:           " << itr -> Adresat::pobierzNazwisko() << endl;
                cout << "Numer Telefonu:     " << itr -> Adresat::pobierzNumerTelefonu() << endl;
                cout << "Email:              " << itr -> Adresat::pobierzEmail() << endl;
                cout << "Adres:              " << itr -> Adresat::pobierzAdres() << endl;
                cout << "-------------------------" << endl;
                iloscOsob++;
            }
        }
        cout << endl;
        if(iloscOsob == 0)
            cout << "Brak wpisow w ksiazce adresowej" << endl;

        cout << "Nacisnij dowolny klawisz..." << endl;
        getch();
    }
}

int KsiazkaAdresowa::rozdzielWczytanaLinie(string wczytanaLinia, char znak) {

    int numerPojedynczejDanej = 1;
    int idAdresat = 0;
    stringstream ss(wczytanaLinia);
    string pojedynczaDana = "";

    while(getline(ss, pojedynczaDana, znak)) {

        switch(numerPojedynczejDanej) {
        case 1:
            idAdresat = atoi(pojedynczaDana.c_str());
            break;
        }
        numerPojedynczejDanej++;
    }
    return idAdresat;
}

int KsiazkaAdresowa::zwrocNumerLiniiWKtorejJestAdresat(int idEdytowanegoAdresata) {

    fstream plik;
    int numerLinii = 1;
    string wczytanaLinia = "";
    int iD = 0;

    plik.open("Adresaci.txt", ios::in);

    while(getline(plik, wczytanaLinia)) {

        iD = rozdzielWczytanaLinie(wczytanaLinia, '|');

        if(idEdytowanegoAdresata == iD)
            return numerLinii;
        else
            numerLinii++;
    }
    plik.close();
}

void KsiazkaAdresowa::aktualizujDanePoUsunieciuAdresata(int numerAdresataDoUsuniecia) {

    fstream plik, tymczasowy;
    int numerLiniiWKtorejJestAdresat = 0;
    int numerLinii = 1;
    string wczytanaLinia = "";

    numerLiniiWKtorejJestAdresat = zwrocNumerLiniiWKtorejJestAdresat(numerAdresataDoUsuniecia);

    plik.open("Adresaci.txt", ios::in);
    tymczasowy.open("Tymczasowy.txt", ios::out | ios::app);

    if(plik.good() == true || numerLiniiWKtorejJestAdresat != 0) {

        while(getline(plik, wczytanaLinia)) {

            if(numerLinii == numerLiniiWKtorejJestAdresat) {;}

            else if(numerLinii == 1 && numerLiniiWKtorejJestAdresat != numerLinii) {

                tymczasowy << wczytanaLinia;

            }
            else if(numerLinii > 1 && numerLiniiWKtorejJestAdresat != 1) {

                tymczasowy << endl << wczytanaLinia;

            }
            else if(numerLinii == 2 && numerLiniiWKtorejJestAdresat == 1) {

                tymczasowy << wczytanaLinia;

            }
            else if(numerLinii > 2 && numerLiniiWKtorejJestAdresat == 1) {

                tymczasowy << endl << wczytanaLinia;
            }
            numerLinii++;
        }
        plik.close();
        tymczasowy.close();

        remove("Adresaci.txt");
        rename("Tymczasowy.txt", "Adresaci.txt");
    }
}

void KsiazkaAdresowa::usunAdresata() {

    system("cls");
    Uzytkownik uzytkownik;
    int numerAdresataDoUsuniecia = 0;
    char znak, wybor;;
    bool czyIstniejeAdresat = false;
    vector<Adresat>::iterator itr = adresaci.begin();

    cout << "-----Spis kontaktow w ksiazce adresowej-----" << endl;
    if(!adresaci.empty()) {

        wyswietlWszystkichAdresatow();

        cout << "Podaj numer adresata ktorego chcesz usunac: ";
        cin >> numerAdresataDoUsuniecia;

        if (cin.fail()) {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl;
            cin.clear();
            cin.sync();
        } else {
            for(itr = adresaci.begin(); itr != adresaci.end(); itr++) {

                if(this -> idZalogowanegoUzytkownika == itr -> Adresat::pobierzIdUzytkownika()) {

                    czyIstniejeAdresat = true;
                    cout << "Jesli chcesz usunac wybranego adresata potwierdz naciskajac klawisz t/T: ";
                    cin >> znak;

                    if(znak == 't' || znak == 'T') {

                        itr = adresaci.erase(itr);
                        aktualizujDanePoUsunieciuAdresata(numerAdresataDoUsuniecia);
                        cout << endl << "Wskazany kontakt zostal USUNIETY" << endl << endl;
                        break;

                    }
                    else {
                        cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                        break;
                    }
                    cout << endl;
                    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
                    wybor = getch();
                }
            }
            if (czyIstniejeAdresat == false) {
                cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            }
        }
    }
    else {
        cout << endl;
        cout << "Ksiazka adresowa pusta. Przejdz do opcji dodawania adresatow." << endl;
    }
    system("pause");
}

char KsiazkaAdresowa::menuEdycjiAdresata(int numerAdresataDoEdycji) {

    system("cls");
    char wyborDanych;

    vector<Adresat>::iterator itr = adresaci.begin();

    while(itr != adresaci.end()) {

        cout << "-----Panel edycji kontaktu-----" << endl;

        cout << endl;

        cout << "Id:                 " << itr -> Adresat::pobierzIdAdresat() << endl;
        cout << "IdUzytkownik:       " << itr -> Adresat::pobierzIdUzytkownika() << endl;
        cout << "Imie:               " << itr -> Adresat::pobierzImie() << endl;
        cout << "Nazwisko:           " << itr -> Adresat::pobierzNazwisko() << endl;
        cout << "Numer Telefonu:     " << itr -> Adresat::pobierzNumerTelefonu() << endl;
        cout << "Email:              " << itr -> Adresat::pobierzEmail() << endl;
        cout << "Adres:              " << itr -> Adresat::pobierzAdres() << endl;
        cout << "-------------------------" << endl;

        cout << endl;
        cout << "-----Wybierz dostepne opcje-----" << endl;
        cout << "1. Zmiana imienia" << endl;
        cout << "2. Zmiana nazwiska" << endl;
        cout << "3. Zmiana numeru telefonu" << endl;
        cout << "4. Zmiana adresu email" << endl;
        cout << "5. Zmiana adresu" << endl;
        cout << "6. Powrot" << endl;
        cout << endl << "Wybierz 1-6: ";
        cin >> wyborDanych;
        return wyborDanych;
    }
    itr++;
}

string KsiazkaAdresowa::konwersjaIntNaString(Adresat adresat) {

    int i = adresat.pobierzIdAdresat();
    ostringstream ss;
    ss << i;
    return  ss.str();
}

string KsiazkaAdresowa::konwersjaIntNaStringDruga(Adresat adresat) {

    int i = adresat.pobierzIdUzytkownika();
    ostringstream ss;
    ss << i;
    return  ss.str();
}

string KsiazkaAdresowa::zmienDaneAdresataNaLiniezDanymiOddzielonePionowaKreska(Adresat adresat) {

    string liniaZNowymiDanymiAdresata = "";

    liniaZNowymiDanymiAdresata += konwersjaIntNaString(adresat) + "|";
    liniaZNowymiDanymiAdresata += konwersjaIntNaStringDruga(adresat) + "|";
    liniaZNowymiDanymiAdresata += adresat.pobierzImie() + "|";
    liniaZNowymiDanymiAdresata += adresat.pobierzNazwisko() + "|";
    liniaZNowymiDanymiAdresata += adresat.pobierzNumerTelefonu() + "|";
    liniaZNowymiDanymiAdresata += adresat.pobierzEmail() + "|";
    liniaZNowymiDanymiAdresata += adresat.pobierzAdres() + "|";

    return liniaZNowymiDanymiAdresata;
}

void KsiazkaAdresowa::edytujWybranaLinieWPliku(int numerLiniiEdytowanegoAdresata, string liniaZNowymiDanymi) {

    fstream plik,tymczasowy;
    int numerLinii = 1;
    string wczytanaLinia = "";

    plik.open("Adresaci.txt", ios::in);
    tymczasowy.open("Tymczasowy.txt", ios::out | ios::app);

    if(plik.good() == true) {

        while(getline(plik, wczytanaLinia)) {

            if(numerLinii == numerLiniiEdytowanegoAdresata) {

                if(numerLinii == 1) {

                    tymczasowy << liniaZNowymiDanymi;

                }
                else if(numerLinii > 1) {

                    tymczasowy << endl << liniaZNowymiDanymi;
                }
            }
            else {
                if(numerLinii == 1) {
                    tymczasowy << wczytanaLinia;
                }
                else if(numerLinii > 1) {
                    tymczasowy << endl << wczytanaLinia;
                }
            }
            numerLinii++;
        }
        plik.close();
        tymczasowy.close();

        remove("Adresaci.txt");
        rename("Tymczasowy.txt", "Adresaci.txt");
    }
}

void KsiazkaAdresowa::aktualizaujDaneEdytowanegoAdresata(Adresat adresat, int idAdresat) {

    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymi = "";

    numerLiniiEdytowanegoAdresata = zwrocNumerLiniiWKtorejJestAdresat(idAdresat);
    liniaZDanymi = zmienDaneAdresataNaLiniezDanymiOddzielonePionowaKreska(adresat);
    edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymi);
}

void KsiazkaAdresowa::panelEdycjiAdresata(char wyborUzytkownika, int numerAdresataDoEdycji) {

    vector<Adresat>::iterator itr = adresaci.begin();
    string  imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";


    for(itr; itr != adresaci.end(); itr++) {

        switch(wyborUzytkownika) {
        case '1':
            cout << "Podaj nowe imie: ";
            cin >> imie;
            itr -> Adresat::ustawImieAdresata(imie);
            aktualizaujDaneEdytowanegoAdresata(*itr, numerAdresataDoEdycji);
            cout << "Zapisano pomyslnie zmiany" << endl;
            return;
        case '2':
            cout << "Podaj nowe nazwisko: ";
            cin >> nazwisko;
            itr -> Adresat::ustawNazwiskoAdresata(nazwisko);
            aktualizaujDaneEdytowanegoAdresata(*itr, numerAdresataDoEdycji);
            cout << "Zapisano pomyslnie zmiany" << endl;
            return;
        case '3':
            cout << "Podaj nowy numer telefonu: ";
            cin.sync();
            getline(cin, numerTelefonu);
            itr -> Adresat::ustawNumerTelefonu(numerTelefonu);
            aktualizaujDaneEdytowanegoAdresata(*itr, numerAdresataDoEdycji);
            cout << "Zapisano pomyslnie zmiany" << endl;
            return;
        case '4':
            cout << "Podaj nowy adres email: ";
            cin >> email;
            itr -> Adresat::ustawEmail(email);
            aktualizaujDaneEdytowanegoAdresata(*itr, numerAdresataDoEdycji);
            cout << "Zapisano pomyslnie zmiany" << endl;
            return;
        case '5':
            cout << "Podaj nowy adres: ";
            cin.sync();
            getline(cin, adres);
            itr -> Adresat::ustawAdres(adres);
            aktualizaujDaneEdytowanegoAdresata(*itr, numerAdresataDoEdycji);
            cout << "Zapisano pomyslnie zmiany" << endl;
            return;
        case '6':
            return;
        }
    }
}

void KsiazkaAdresowa::edytujAdresata() {

    system("cls");
    Uzytkownik uzytkownik;
    int numerAdresataDoEdycji = 0;
    char znak, wybor;;
    bool czyIstniejeAdresat = false;
    vector<Adresat>::iterator itr = adresaci.begin();

    cout << "-----Spis kontaktow w ksiazce adresowej-----" << endl;

    if(!adresaci.empty()) {

        wyswietlWszystkichAdresatow();

        cout << "Podaj numer adresata ktorego chcesz edytowac: ";
        cin >> numerAdresataDoEdycji;

        if(cin.fail()) {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl << endl;
            cin.clear();
            cin.sync();
        }
        else {

            if(this -> idZalogowanegoUzytkownika == itr -> Adresat::pobierzIdUzytkownika()) {

                czyIstniejeAdresat = true;
                wybor = menuEdycjiAdresata(numerAdresataDoEdycji);
                panelEdycjiAdresata(wybor, numerAdresataDoEdycji);
            }
            if(czyIstniejeAdresat == false) {
                cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            }
        }
    }
    else {
        cout << endl;
        cout << "Ksiazka adresowa pusta. Przejdz do opcji dodawania adresatow." << endl;
    }
    system("pause");
}
