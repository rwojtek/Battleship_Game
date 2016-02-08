#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Gra statki.h"

using std::cout;
using std::cin;
using std::endl;

///-----------------------------------------------------
///---------------------- PLANSZA ----------------------
///-----------------------------------------------------

Plansza::Plansza()
{
	int i, j;
	char k;
    wierszZEROWY[0] = 255;

                                                    // wypelnienie wierszZEROWY A-J, wierszZEROWY[0] = 255;
    for (i=1, k='A'; i<kolumna; i++, k++)
        wierszZEROWY[i] = k;
                                                    // wypelnienie kolumnaZEROWA 1-10
    for (i=0; i<wiersz; i++)
        kolumnaZEROWA[i] = i;
                                                    // wypelnianie "ciala" planszy
	for (i=0; i<wiersz; i++)
    	for (j=0; j<kolumna; j++)
        	plansza[i][j] = symbolPola;
}
//*******************************************************************

void Plansza::wyswietl()
{
    int i, j;

    cout << "\t\b\b\b\b";
                                                    // wyswietlenie wierszZEROWY A-J, elementow o indeksach [0] i [kolumna-1] nie pokazujemy
    for (i=1; i<kolumna-1; i++)
        cout << wierszZEROWY[i] << "  ";
                                                    // wyswietlanie kolumnaZEROWA 1-10 i "cialo" planszy
    cout << endl << endl;
    for (i=1; i<wiersz-1; i++)
    {
        cout << kolumnaZEROWA[i] << "\t\b\b\b\b";
                                                    // wyswietlenie kolumnaZEROWA 1-10, elementow o indeksach [0] i [kolumna-1] nie pokazujemy
        for (j=1; j<kolumna-1; j++)
            cout << plansza[i][j] << "  ";
            cout << endl << endl;
    }
}

///---------------------------------------------------
///---------------------- GRACZ ----------------------
///---------------------------------------------------
void Gracz::setImie()
{
    static int ktoryGracz = 1;
    if (ktoryGracz == 3)                            // na wypadek ponownej gry bez wychodzenie z okna konsoli
        ktoryGracz = 1;
    cout << "Podaj imie #" << ktoryGracz++ << " gracza: ";
    getline(cin, imie);
}
//*******************************************************************

void Gracz::rozmiescStatki(Gracz gracz)
{
    cout << gracz.imie <<  ", przygotuj sie do rozmieszczenia statkow...";
    Sleep(2000);
    system("CLS");
                                                            // wyswietlenie wypelnionej pustymi polami planszy Statkow
    planszaStatki.wyswietl();
                                                            // podanie wspolrzednych 1 statku
    cout << endl;
    cout << gracz.imie << ", podaj wspolrzedne #1 statku: ";
    int x, y;
    char xTemp;                                             // zmienna pomocnicza dostajaca char i bedaca zamieniana na int
    cin >> y;
    cin >> xTemp;

                                                            // "zamiana" char xTemp na int x
    if (toupper(xTemp) == 'A')		x = 1;
    else if (toupper(xTemp) == 'B') x = 2;
    else if (toupper(xTemp) == 'C') x = 3;
    else if (toupper(xTemp) == 'D')	x = 4;
    else if (toupper(xTemp) == 'E')	x = 5;
    else if (toupper(xTemp) == 'F')	x = 6;
    else if (toupper(xTemp) == 'G')	x = 7;
    else if (toupper(xTemp) == 'H')	x = 8;
    else if (toupper(xTemp) == 'I')	x = 9;
    else if (toupper(xTemp) == 'J')	x = 10;
                                                            // zapisanie lokalizacji 1-ego statku
    planszaStatki.plansza[y][x] = sybmolStatku;

    system("CLS");
    planszaStatki.wyswietl();
                                                            // podanie wspolrzednych pozostalych statkow
	for (int n=2; n<=ileStatkow; n++)
	{
        cout << endl;
		cout << gracz.imie << ", podaj wspolrzedne #" << n << " statku: ";

		bool dubel = true;
                                                            // petla while w celu uniemozliwienia wprowadzenia statku w miejsce w ktorym juz jest i "do okola"
        while(dubel == true)
        {
            cin >> y;
            cin >> xTemp;
                                                            // "zamiana" char xTemp na int x
            if (toupper(xTemp) == 'A')		x = 1;
            else if (toupper(xTemp) == 'B') x = 2;
            else if (toupper(xTemp) == 'C') x = 3;
            else if (toupper(xTemp) == 'D')	x = 4;
            else if (toupper(xTemp) == 'E')	x = 5;
            else if (toupper(xTemp) == 'F')	x = 6;
            else if (toupper(xTemp) == 'G')	x = 7;
            else if (toupper(xTemp) == 'H')	x = 8;
            else if (toupper(xTemp) == 'I')	x = 9;
            else if (toupper(xTemp) == 'J')	x = 10;
                                                            // warunek we wskazanych wpolrzednych i polach wokol nie ma juz statku czyli sybmolStatku 'S'
            if (planszaStatki.plansza[y+1][x-1] != sybmolStatku && planszaStatki.plansza[y+1][x] != sybmolStatku && planszaStatki.plansza[y+1][x+1] != sybmolStatku &&
                planszaStatki.plansza[y][x-1] != sybmolStatku && planszaStatki.plansza[y][x] != sybmolStatku && planszaStatki.plansza[y][x+1] != sybmolStatku &&
                planszaStatki.plansza[y-1][x-1] != sybmolStatku && planszaStatki.plansza[y-1][x] != sybmolStatku && planszaStatki.plansza[y-1][x+1] != sybmolStatku)
            {
                planszaStatki.plansza[y][x] = sybmolStatku;
                dubel = false;
            }
            else
            {
                cout << "Nie mozesz tu umiescic statkow. Wskaz inne miejsce: ";
                dubel = true;
            }
        }

		system("CLS");
                                                        // wyswietlanie calej planszy (po dodaniu n-tego statku)
        planszaStatki.wyswietl();
        cout << endl;
	}
	cout << "Statki rozmieszczone przez gracza " << gracz.imie << endl << endl;
	cout << "Nacisnij ENTER, by kontynuowac...";
	getch();
}
//*******************************************************************

void Gracz::strzelanie(char planszaPrzeciwnika[][kolumna], Gracz gracz, int * ptrLicznikTrafionych)
{
    cout << "Strzela " << gracz.imie << "..." <<endl << endl;
                                                            // wyswietlonej wypelnionej pustymi polami planszy Strzalow
    planszaStrzal.wyswietl();
	cout << endl;
                                                            // podanie swojego 1 strzalu
    cout << gracz.imie << ", podaj wspolrzedne strzalu: ";

    bool dubel = true;
                                                            // petla while w celu uniemozliwienia oddania strzalu w miejsce juz wczesniej zestrzelone lub "do okola"
    while(dubel == true)
    {
		int x, y;
		char xTemp;                                         // zmienna pomocnicza dostajaca char i bedaca zamieniana na int
        cin >> y;
        cin >> xTemp;
                                                            // "zamiana" char xTemp na int x
        if (toupper(xTemp) == 'A')		x = 1;
        else if (toupper(xTemp) == 'B') x = 2;
        else if (toupper(xTemp) == 'C') x = 3;
        else if (toupper(xTemp) == 'D')	x = 4;
        else if (toupper(xTemp) == 'E')	x = 5;
        else if (toupper(xTemp) == 'F')	x = 6;
        else if (toupper(xTemp) == 'G')	x = 7;
        else if (toupper(xTemp) == 'H')	x = 8;
        else if (toupper(xTemp) == 'I')	x = 9;
        else if (toupper(xTemp) == 'J')	x = 10;
                                                            // jezeli juz zestrzelony lub " do okola" to dubel zmieniamy na true i wracamy do poczatku petli
        if (planszaStrzal.plansza[y][x] == (char)symbolTrafiony || planszaStrzal.plansza[y][x] == (char)symbolZuzyte)
        {
            cout << "Nie mozesz strzelac juz w to miejsce. Wskaz inne: ";
            dubel = true;
        }
                                                            // jezeli pierwszy if nie jest prawda to sprawdzamy czy nie trafilismy, jesli nie to dubel == false i konczymy metode
    	else if (planszaPrzeciwnika[y][x] != sybmolStatku)
        {
            planszaStrzal.plansza[y][x] = symbolZuzyte;
            system("CLS");
            cout << "Strzela " << gracz.imie << "..." <<endl << endl;
            planszaStrzal.wyswietl();
            cout << "\Pudlo! Pozostalo Ci do zbicia statkow: " << ileStatkow - *ptrLicznikTrafionych << endl << endl;
            dubel = false;
        }
                                                            // jezeli 2 pierwsze warunki nie sa przwdziwe to sprawdzamy czy we wskazanych wspolrzednych planszyStatkow przeciwnika jest S jak statek, jesli jest to trafiony i ++
        else if (planszaPrzeciwnika[y][x] == sybmolStatku)
        {
                                                            // pole [y][x] zmieniamy na krzyz (197) a pola do okola na strukture siatki (176)
            planszaStrzal.plansza[y][x] = symbolTrafiony;
                planszaStrzal.plansza[y+1][x-1] = symbolZuzyte;
                planszaStrzal.plansza[y+1][x] 	= symbolZuzyte;
                planszaStrzal.plansza[y+1][x+1] = symbolZuzyte;
                planszaStrzal.plansza[y][x-1] 	= symbolZuzyte;
                planszaStrzal.plansza[y][x+1] 	= symbolZuzyte;
                planszaStrzal.plansza[y-1][x-1] = symbolZuzyte;
                planszaStrzal.plansza[y-1][x] 	= symbolZuzyte;
                planszaStrzal.plansza[y-1][x+1] = symbolZuzyte;
            system("CLS");
            cout << "Strzela " << gracz.imie << "..." <<endl << endl;
            planszaStrzal.wyswietl();
            (*ptrLicznikTrafionych)++;
            cout << "\nTrafiony! Pozostalo Ci do zbicia statkow: " << ileStatkow - *ptrLicznikTrafionych << endl << endl;
            dubel = false;
        }
    }
}
///-------------------------------------------------
///---------------------- GRA ----------------------
///-------------------------------------------------

void Gra::startGry()
{
    cout << "=========================================" << endl;
    cout << "========= WITAJ W GRZE W STATKI =========" << endl;
    cout << "=========================================" << endl;
    cout << endl << endl;
    cout << "Zasady gry:" << endl << endl;
    cout << "1) Kazdy z graczy rozmieszcza statki w ilosci: " << ileStatkow << " (statki nie moga sie stykac)" << endl;
    cout << "2) Gracze na przemian zatapiaja statki przeciwnika." << endl;
    cout << "   Wygrywa ten kto pierwszy zatopi wszystkie statki" << endl << endl;
    cout << "******************************************************" << endl << endl;
    cout << "Aby rozpoczac nowa gre nacisnij 'S', aby wyjsc z programu nacisnij 'Z': ";

    char ch;
                                                                        // czy start gry czy koniec
    if ((cin >> ch).get() && toupper(ch) == 'S')
        przebiegGry();
    else if (toupper(ch) == 'Z')
        cout << "\nSzkoda, ze juz konczysz. Do zobaczenia!\n";
}

void Gra::przebiegGry()
{
    cout << endl;
                                                                        // 1) Podanie imion graczy i rozpoczecie gry
    gracz1.setImie();
    gracz2.setImie();

    cout << endl;
    cout << "Do gry przystepuja " << gracz1.getImie() << " oraz " << gracz2.getImie() << ". Zaczynamy!...";
    Sleep(2000);
    system("CLS");
                                                                        // 2) Rozmieszczanie statków przez graczy
    gracz1.rozmiescStatki(gracz1);
    system("CLS");
    gracz2.rozmiescStatki(gracz2);
                                                                        // 3) Rozpoczecie zestrzeliwania statkow przeciwnika
    system("CLS");
    cout << "Statki rozlokowane. Przystepujemy do strzelania...";
    Sleep(2000);
    system("CLS");
                                                                        // ta petla powinna sie znalezc w metodzie strzelani() raczej, choc jak chcialem ja tam wcisnac to czegos mi tam brakowalo...
    while (true)                                                    // petla ma dzialac bez warunku bo przerywa ja break
    {
                                                                        // strzela gracz1 w plansze Statkow gracza2
        gracz1.strzelanie(gracz2.planszaStatki.plansza, gracz1, &gracz1.licznikTrafionych);
            if (gracz1.licznikTrafionych == ileStatkow) {                          // warunek wygranej
                cout << "Brawo " << gracz1.getImie() << ", wygrales!!!" << endl;
                break;
            }
        cout << "Nacisnij ENTER, by kontynuowac...";
        getch();
        system("CLS");
                                                                                // strzela gracz2 w plansze Statkow gracza1
        gracz2.strzelanie(gracz1.planszaStatki.plansza, gracz2, &gracz2.licznikTrafionych);
            if (gracz2.licznikTrafionych == ileStatkow) {
                cout << "Brawo " << gracz2.getImie() << ", wygrales!!!" << endl << endl;
                break;
            }
        cout << "Nacisnij ENTER, by kontynuowac...";
        getch();
        system("CLS");
    }
    koniecGry();
}

void Gra::koniecGry()
{
                                                                        // czy gramy jeszcze raz?
    cout << "\nChcesz zagrac jeszcze raz? (T/N): \n";
    cout << endl;
    char ch;

    if ((cin >> ch).get() && toupper(ch) == 'T')
    {
        system("CLS");
                                                                        // jesli TAK to zaczynamy od nowa, jak na nowo wypelnic plansze skoro wypelniana jest ona w konstruktorze? zamiast konstruktora metoda wypelnij()?
        startGry();
    }
                                                                        // jesli NIE to koniec
    else if (toupper(ch) == 'N')
        cout << "\nDziekujemy za gre. Zapraszamy ponownie!\n";
}


