#include <iostream>
#include <limits>
#include <string>
using namespace std;
//https://eduinf.waw.pl/inf/utils/002_roz/mp001.php
struct Lisc {
    int wartosc;
    int indexOjca;
    int indexLewego;
    int indexPrawego;
    bool jest;
    int indexWlasny;
};

void wyswietlAktualnyRozmiar(int aktualnyRozmiar){

    cout << "aktualnyRozmiar: "<< aktualnyRozmiar << endl;
}
void wyswietlDrzewo(Lisc tabelka[], int aktualnyRozmiarTableki)
{
    for(int i=0; i<aktualnyRozmiarTableki; i++){
        cout
        << "wart:" << tabelka[i].wartosc << ", "
        << "ind: "<< i << ", "
        << "indWlas: " <<  tabelka[i].indexWlasny << ", "
        << "indOjca: " <<  tabelka[i].indexOjca << ", "
        << "indLewe: " <<  tabelka[i].indexLewego << ", "
        << "indPraw: " <<  tabelka[i].indexPrawego //<< ", "
        //<< "jest: " <<  tabelka[i].jest
        << endl;
    }
    if(aktualnyRozmiarTableki == 0) {
       cout << "drzewo puste !!!" << endl;
    }
    else{
        wyswietlAktualnyRozmiar(aktualnyRozmiarTableki);
    }

}


void dodajElementDoDrzewa(Lisc tabelka[], int * aktualnyRozmiarTableki, int nowyElement)
{
    int indexNowegElementu = *aktualnyRozmiarTableki;

    int aktualniePrzeszukiwanyElement = 0;

    Lisc n; // listek nowy
    n.wartosc = nowyElement;
    n.indexWlasny = (*aktualnyRozmiarTableki);
    n.indexLewego = -1;
    n.indexPrawego = -1;
    n.indexOjca = -1;
    n.jest = true;


    if((*aktualnyRozmiarTableki) < 20)
    {
        if((*aktualnyRozmiarTableki) == 0){
            n.indexWlasny = 0;
            tabelka[0] = n;
        }
        else{
            Lisc x = tabelka[0]; // listek head
            Lisc y; // lsitek aktualnie przeszukwiany;

            int index = 0;
            while(x.jest == true && index >= 0){

                y = x;
                if(n.wartosc < x.wartosc){
                    index = x.indexLewego;
                    x = tabelka[x.indexLewego];
                }
                else{
                    index = x.indexPrawego;
                    x = tabelka[x.indexPrawego];
                }
            }

            n.indexOjca = y.indexWlasny;

            if(n.wartosc < y.wartosc){
                y.indexLewego = n.indexWlasny;
            }
            else{
                y.indexPrawego = n.indexWlasny;
            }
            tabelka[y.indexWlasny] = y;
            tabelka[n.indexWlasny] = n;
        }


        (*aktualnyRozmiarTableki)++;
    }
    else
    {
        cout << "Drzewo jest pe³ne!!!";
    }
    //wyswietlAktualnyRozmiar( (*aktualnyRozmiarTableki));

}

int zapytajOElement(){
    int num;
    bool blad = false;
    while(true)
    {
        if(blad){
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
        }
        cout << "Podaj Wartosc: ";
        cin >> num;

        if(cin.fail()){
            cout << "podana wartosc to nie liczba" << endl;
            blad = true;
        }
        else{
            break;
        }
    }
    return num;
}

void wyzerujTablice(Lisc tabelka[], int maksymalnyRozmiarTab, int * aktualnyRozmiarTab){

    for(int i=0; i<(*aktualnyRozmiarTab); i++){
        delete (&tabelka[i]);
    }
    (*aktualnyRozmiarTab) = 0;
}

int main()
{
    cout << "Symulator drzewa BST na tablicy!!!" << endl;

    const int maxRozmiar = 20;
    Lisc dane[maxRozmiar] = {};
    int aktualnyRozmiar = 0;

    string tekst;
    while(true)
    {
        cout << endl << "1-Dodawanie wartosci; 2-Wyswietl drzewo; 3-Kasowanie drzewa; 4-Koniec" << endl;
        cin >> tekst;
        if(tekst == "1" )
        {
            int nowaLiczba = zapytajOElement();
            //wyswietlAktualnyRozmiar(aktualnyRozmiar);
            dodajElementDoDrzewa(dane, &aktualnyRozmiar, nowaLiczba);
            wyswietlDrzewo(dane, aktualnyRozmiar);
        }
        else if(tekst == "2"){
            cout << "Wyswietl drzewo" << endl;
            wyswietlDrzewo(dane, aktualnyRozmiar);
        }
        else if(tekst == "3"){
            cout << "Kasowanie drzewa" << endl;
            wyzerujTablice(dane, maxRozmiar, &aktualnyRozmiar);
        }
        else if(tekst == "4"){
            cout << "KONIEC!!!" << endl;
            break;
        }
        else {
            cout << "Brak takiej opcji" << endl;
        }

    }

    return 0;
}
