#include <iostream>
#include <fstream>

#include<cstdlib>

#include <sys/time.h>

using namespace std;


void wczytywaniePliku1(int tab[], string nazwaPliku, int rozmiar){

    ifstream file(nazwaPliku.c_str());

    if (file.is_open()) {
        string line;
        int i = 0;
        while (getline(file, line)) {
            if(i >= rozmiar) break;
            tab[i] = atoi(line.c_str());
            i++;
        }
        file.close();
    }
}

void wczytywaniePliku2(int tab[], string nazwaPliku, int rozmiar){

    ifstream infile(nazwaPliku.c_str());
    int i = 0;
    if (infile.is_open()) {
        while (infile >> tab[i])
        {
            if(i >= rozmiar) break;
            i++;
        }
        infile.close();
    }
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    cout << "...Sortowanie bablekowe..." << endl;
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}


void selectionSort(int arr[], int n)
{
    cout << "...Sortowanie przez wybieranie..." << endl;
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[100000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}
// Merge sort


void wyswietlTablice(int tab[], int rozmiar)
{
    cout << "Wyswietlenie elementow tablicy" << endl;
    for (int i = 0; i < rozmiar; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void kopiowanieTablicy(int tabZrodlo[], int tabCel[], int rozmiar)
{
    cout << "kopiowanieTablicy" << endl;
    for (int i = 0; i < rozmiar; i++)
    {
        tabCel[i] = tabZrodlo[i];
    }
}

void pomiarCzasuStart(struct timeval* begin){
    gettimeofday(begin, 0); // Start measuring time
}

void pomiarCzasuStopIWyniki(struct timeval* begin, struct timeval* end){
    gettimeofday(end, 0);  // Stop measuring time and calculate the elapsed time
    long seconds = (*end).tv_sec - (*begin).tv_sec;
    long microseconds = (*end).tv_usec - (*begin).tv_usec;
    double elapsed = seconds + microseconds*1e-9;

    cout << "Czas wykonania: " << elapsed << endl;
}

int main()
{
    cout << "Program do sortowania!!!" << endl;


    int rozmiar = 10000;
    int dane[rozmiar];

    int n = sizeof(dane)/sizeof(dane[0]); //dynamicznyc pomiar rozmiaru tablicy
    cout << n << endl;


    string fileName = "WE_NP_100000.txt" ;


    wczytywaniePliku1(dane, fileName, rozmiar);
    //wyswietlTablice(dane, rozmiar);


    //TEST nr 1
    int dane1[rozmiar];
    kopiowanieTablicy(dane, dane1, rozmiar);

    struct timeval begin1, end1;
    pomiarCzasuStart(&begin1);

    bubbleSort(dane1,rozmiar);

    pomiarCzasuStopIWyniki(&begin1,&end1);
    //wyswietlTablice(dane1, rozmiar);

    //TEST nr 2
    int dane2[rozmiar];
    kopiowanieTablicy(dane, dane2, rozmiar);

    struct timeval begin2, end2;
    pomiarCzasuStart(&begin2);

    cout << "...merge_sort..." << endl;
    merge_sort(dane2, 0, rozmiar-1);

    pomiarCzasuStopIWyniki(&begin2,&end2);
    //wyswietlTablice(dane1, rozmiar);

    //TEST nr 1
    int dane3[rozmiar];
    kopiowanieTablicy(dane, dane3, rozmiar);

    struct timeval begin3, end3;
    pomiarCzasuStart(&begin3);

    selectionSort(dane3,rozmiar);

    pomiarCzasuStopIWyniki(&begin3,&end1);
    //wyswietlTablice(dane1, rozmiar);


    return 0;
}
