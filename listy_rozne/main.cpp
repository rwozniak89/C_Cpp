#include <iostream>

#include <algorithm>
#include <iostream>
#include <list>
#include <chrono>
using namespace std;
//using namespace std::chrono;
// MENU -> Project -> Build options... -> in [Debug], in [Compiler settings], in [Compiler Flags] -> zaznacz Have g++ ... C++0x ISO C++ ...
//https://eu-prod.asyncgw.teams.microsoft.com/v1/objects/0-weu-d7-50d7d082e4858ba4052f75b4549e7326/views/imgo

/*
void dodajDoListyElementyZaPomocaWsk(list<int>* listeczka, int a, int b){
    for(int i = a; i <=b; i++){
        (*listeczka).push_back(i);
	}
}
*/
/*void testListy(){
    cout << "Hello world!" << endl;
    std::list<int> my_list = { 12, 5, 10, 9 };
	for (int x : my_list) {
		std::cout << x << '\n';
	}
}*/

// operacje na liscie STL
list<int> dodajElementyDoListySTL(list<int> listeczka, int a, int b){

    cout << "Dodanie do listy STL: ";
    for(int i = a; i <=b; i++){
        listeczka.push_back(i);
	}
    cout << (b-a+1) << " elementow..." << '\n';
    return listeczka;
}

void wywietlElementyListySTL(list<int> listeczka){
	cout << "Zawartosc listy: ";
	for (int x : listeczka) {
		cout << x << ' ';
	}
	//for (auto it = listeczka.cbegin(); it != listeczka.cend(); it++)
    //{
    //    cout << *it << ' ';
    //}
    cout << '\n';
}

void obliczSredniaLiczbListySTL(list<int> listeczka){
	long long int suma = 0;
	int liczbaLiczb = 0;
	cout << "Obliczanie srendiej liczb z listy o " << listeczka.size() << " elementach" << endl;
	for (auto it = listeczka.cbegin(); it != listeczka.cend(); it++)
    {
        suma += (*it);
        liczbaLiczb++;
    }

    if(liczbaLiczb > 0){
        float srednia = suma/(float)liczbaLiczb;
        cout << "Srednia to:" << srednia << endl;
    }
}

list<int> usuwanieLiczbNieparzystychZListySTL(list<int> listeczka){
	int licznik = 0;
	for (auto it = listeczka.cbegin(); it != listeczka.cend(); it++)
    {
        if((*it) % 2 == 1){
            listeczka.erase(it);
            licznik++;
        }
    }
    cout << "usunieto z listy:" << licznik << "elementow..." <<endl;
    return listeczka;
}


// budowa listy wskaznikowej z operacjami
class List {
    struct Node {
        int data;
        Node * next;
    };

    Node * head;

public:
    List() {
        head = NULL;
    }

    ~List() {
        while(head != NULL) {
            Node * n = head->next;
            delete head;
            head = n;
        }
    }

    void add(int value) {
        Node * n = new Node;
        n->data = value;
        n->next = head;
        head = n;
    }

    void print() {
        cout << "Zawartosc listy WSK: ";
        Node * ptr = head;
        while(ptr != NULL) {
            cout << ptr->data << ' ';
            Node * n = ptr->next;
            ptr = n;
        }
        cout << '\n';
    }

    void srednia() {
        Node * ptr = head;
        long long int suma = 0;
        int liczbaLiczb = 0;
        while(ptr != NULL) {
            suma += (ptr->data);
            Node * n = ptr->next;
            ptr = n;
            liczbaLiczb++;
        }
        cout << "Obliczanie srendiej liczb z listy o " << liczbaLiczb << " elementach" << endl;
        if(liczbaLiczb > 0){
            float srednia = suma/(float)liczbaLiczb;
            cout << "Srednia to:" << srednia << endl;
        }
    }

    void delete_item(Node** head, int i) {
      for (Node** current = head; *current; current = &(*current)->next) {
        if ((*current)->data == i) {
          Node* next = (*current)->next;
          delete *current;
          *current = next;
          break;
        }
      }
    }

    void usunNieparzyste() {
        int licznik=0;
        Node * ptr = head;
        while(ptr != NULL) {
            int x = ptr->data;
            if( x % 2 == 1){
                 delete_item(&head, x);
                 licznik++;
            }
            Node * n = ptr->next;
            ptr = n;
        }
        cout << "usunieto z listy:" << licznik << "elementow..." <<endl;
    }
};


//operacje na liscie WSK
List dodajElementyDoListyWSK(List listeczka, int a, int b){
    cout << "Dodanie do listy: ";
    for (int i=b; i>=a; i--){
        listeczka.add(i);
    }
    cout << (b-a+1) << " elementow..." << '\n';
    return listeczka;
}

//operacje na liscieTAB
vector<int>  dodajElementyDoListyTAB(vector<int> listeczka, int a, int b){
    cout << "Dodanie do listy TAB: ";
    for(int i = a; i <=b; i++){
        listeczka.push_back(i);
	}
    cout << (b-a+1) << " elementow..." << '\n';
    return listeczka;
}
void wywietlElementyListyTAB(vector<int> listeczka){

	cout << "Zawartosc listy: ";
	for (int x : listeczka) {
		cout << x << ' ';
	}
    cout << '\n';
}
void obliczSredniaLiczbListyTAB(vector<int> listeczka){
	long long int suma = 0;
	int liczbaLiczb = 0;
	cout << "Obliczanie srendiej liczb z listy o " << listeczka.size() << " elementach" << endl;
	for (auto it = listeczka.cbegin(); it != listeczka.cend(); it++)
    {
        suma += (*it);
        liczbaLiczb++;
    }

    if(liczbaLiczb > 0){
        float srednia = suma/(float)liczbaLiczb;
        cout << "Srednia to:" << srednia << endl;
    }
}
vector<int> usuwanieLiczbNieparzystychZListyTAB(vector<int>listeczka){
	int licznik = 0;
	for (auto it = listeczka.cbegin(); it != listeczka.cend(); it++)
    {
        if((*it) % 2 == 1){
            listeczka.erase(it);
            licznik++;
        }
    }
    cout << "usunieto z listy:" << licznik << "elementow..." <<endl;
    return listeczka;
}


int main()
{
    int liczbaOd = 1;
    int liczbaDo = 100;

    cout << '\n' << "### LISTA - STL" << endl << endl;

	list<int> listaSTL = {};

    listaSTL = dodajElementyDoListySTL(listaSTL, liczbaOd, liczbaDo);
    wywietlElementyListySTL(listaSTL);
    obliczSredniaLiczbListySTL(listaSTL);
    listaSTL = usuwanieLiczbNieparzystychZListySTL(listaSTL);
    wywietlElementyListySTL(listaSTL);
    obliczSredniaLiczbListySTL(listaSTL);

    cout << '\n' << "### LISTA - WSK" << endl << endl;

    List listaWSK;

    listaWSK = dodajElementyDoListyWSK(listaWSK, liczbaOd, liczbaDo);
    listaWSK.print();
    listaWSK.srednia();
    listaWSK.usunNieparzyste();
    listaWSK.srednia();
    listaWSK.print();

    cout << '\n' << "### LISTA - Tablicowa" << endl << endl;

    vector<int> listaTAB;
    listaTAB = dodajElementyDoListyTAB(listaTAB, liczbaOd, liczbaDo);
    wywietlElementyListyTAB(listaTAB);
    obliczSredniaLiczbListyTAB(listaTAB);
    listaTAB = usuwanieLiczbNieparzystychZListyTAB(listaTAB);
    wywietlElementyListyTAB(listaTAB);
    obliczSredniaLiczbListyTAB(listaTAB);


    return 0;
}
