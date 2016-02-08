#include <iostream>

#ifndef GRA_STATKI
#define GRA_STATKI

using std::string;

const int wiersz = 12;
const int kolumna = 12;
const int ileStatkow = 3;
const char symbolPola = 219;
const char sybmolStatku = 'S';
const char symbolTrafiony = 197;
const char symbolZuzyte = 176;

///---------------------------------
///------------ PLANSZA ------------
///---------------------------------
class Plansza
{
public:
    Plansza();
    int kolumnaZEROWA[wiersz];
    char wierszZEROWY[kolumna];
    char plansza[wiersz][kolumna];
    void wypelnij();
    void wyswietl();
};

///-------------------------------
///------------ GRACZ ------------
///-------------------------------
class Gracz
{
    string imie;
public:
    Plansza planszaStatki;
    Plansza planszaStrzal;
    int licznikTrafionych;

    Gracz() {
        imie = "brak";
        licznikTrafionych = 0;
    }
    void setImie();
    string getImie()
    {
        return imie;
    }
    void rozmiescStatki(Gracz gracz);
    void strzelanie(char planszaPrzeciwnika[][kolumna], Gracz gracz, int * ptrLicznikTrafionych);
};

///-----------------------------
///------------ GRA ------------
///-----------------------------
class Gra
{
    Gracz gracz1;
    Gracz gracz2;
public:
    void startGry();
    void przebiegGry();
    void koniecGry();
};
#endif // GRA_STATKI
