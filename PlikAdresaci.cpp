#include "PlikAdresaci.h"


using namespace std;

PlikAdresaci::PlikAdresaci() {

    this->nazwaPlikuZAdresatami = "Adresaci.txt";
}

PlikAdresaci::~PlikAdresaci() {;}

vector<Adresat> PlikAdresaci::rozdzielanieStringowAdresaci(vector<Adresat> &adresaci, string wczytanaLinia, char znak, int idZalogowanego) {

    Adresat adresat;
    Uzytkownicy uzytkownicy;
    int numerPojedynczejDanej = 1;
    stringstream ss(wczytanaLinia);
    string pojedynczaDana = "";

    while(getline(ss, pojedynczaDana, znak)) {

        switch(numerPojedynczejDanej) {
        case 1:
            adresat.ustawIdAdresata(atoi(pojedynczaDana.c_str()));
            break;
        case 2:
            adresat.ustawIdUzytkownika(atoi(pojedynczaDana.c_str()));
            break;
        case 3:
            adresat.ustawImieAdresata(pojedynczaDana);
            break;
        case 4:
            adresat.ustawNazwiskoAdresata(pojedynczaDana);
            break;
        case 5:
            adresat.ustawNumerTelefonu(pojedynczaDana);
            break;
        case 6:
            adresat.ustawEmail(pojedynczaDana);
            break;
        case 7:
            adresat.ustawAdres(pojedynczaDana);
            break;
        }
        numerPojedynczejDanej++;
    }
    if(adresat.pobierzIdUzytkownika() == idZalogowanego) {

        adresaci.push_back(adresat);
    }
    return adresaci;
}

int PlikAdresaci::pobierzIDOstatniegoAdresataWPliku(string daneOstatniegoAdresataWPliku, char znak) {

    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";
    int idUzytkownik = 0, idAdresat = 0;
    int numerPojedynczejDanej = 1;
    stringstream ss(daneOstatniegoAdresataWPliku);
    string pojedynczaDana = "";

    while(getline(ss, pojedynczaDana, znak)) {

        switch(numerPojedynczejDanej) {
        case 1:
            idAdresat = atoi(pojedynczaDana.c_str());
            break;
        case 2:
            idUzytkownik = atoi(pojedynczaDana.c_str());
            break;
        case 3:
            imie = pojedynczaDana;
            break;
        case 4:
            nazwisko = pojedynczaDana;
            break;
        case 5:
            numerTelefonu = pojedynczaDana;
            break;
        case 6:
            email = pojedynczaDana;
            break;
        case 7:
            adres = pojedynczaDana;
            break;
        }
        numerPojedynczejDanej++;
    }
    return idAdresat;
}

int PlikAdresaci::wczytajPlikAdresaci(vector<Adresat> &adresaci, int idZalogowanego) {

    string wczytanaLinia = "";
    string daneOstatniegoAdresataWPliku = "";
    fstream plik;
    int idOstaniegoAdresataWPliku = 0;

    plik.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if(plik.good() == false) {

        cout << endl << "Plik pusty! Przejdz do opcji dodawania adresatow." << endl << endl;
        system("pause");
        return 0;
    } else {

        while(getline(plik, wczytanaLinia)) {

            adresaci = rozdzielanieStringowAdresaci(adresaci, wczytanaLinia, '|', idZalogowanego);
        }
        daneOstatniegoAdresataWPliku = wczytanaLinia;

        if(daneOstatniegoAdresataWPliku != "") {

            idOstaniegoAdresataWPliku = pobierzIDOstatniegoAdresataWPliku(daneOstatniegoAdresataWPliku, '|');
            return idOstaniegoAdresataWPliku;

        } else
            return idOstaniegoAdresataWPliku = 0;

        plik.close();
    }
}

string PlikAdresaci::pobierzNazwePlikuZAdresatami() {

    return nazwaPlikuZAdresatami;
}
