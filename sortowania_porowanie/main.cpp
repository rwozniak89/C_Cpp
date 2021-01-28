#include <iostream>
#include <fstream>

#include<cstdlib>

#include <sys/time.h>

#include <dirent.h>

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

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge2(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort2(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort2(arr,l,m);
    mergeSort2(arr,m+1,r);
    merge2(arr,l,m,r);
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    cout << "...Sortowanie przez wstawianie ..." << endl;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    cout << "...Sortowanie przez kopcowanie..." << endl;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


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
    //cout << "kopiowanieTablicy" << endl;
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

    cout << "Czas wykonania: " << elapsed <<  "  sek. " << endl;
}

int przeszukiwanieFolderu(string tablicaPlikow[], int tablicaRozmiarowPlikow[], int * licznaPlikow){
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (".\\")) != NULL) {
      /* print all the files and directories within directory */

      while ((ent = readdir (dir)) != NULL) {
        string temp = ent->d_name;
        if(temp.substr(0,3) == "WE_")
        {
            //cout << temp << endl;
            tablicaPlikow[*licznaPlikow] = temp;
            string temp2 = (temp.substr(6, temp.length() -4 -6));
            //cout << temp2 << endl;
            tablicaRozmiarowPlikow[*licznaPlikow] = atoi(temp2.c_str());
            (*licznaPlikow)++;
        }
      }
      closedir (dir);
    } else {
      /* could not open directory */
      perror ("");
      return EXIT_FAILURE;
    }


    for (int i = 0; i < (*licznaPlikow); i++)
    {
        cout << "Znaleziono pliki" << tablicaPlikow[i] << ", o rozmiarze: " << tablicaRozmiarowPlikow[i] << endl;
    }
}

int main()
{
    cout << "Program do porownania sortowania!!!" << endl;


    int rozmiar = 100000;
    int dane[rozmiar];
    int daneKopia[rozmiar];
    struct timeval begin, end;

    //int n = sizeof(dane)/sizeof(dane[0]); //dynamicznyc pomiar rozmiaru tablicy
    //cout << n << endl;

    string tablicaPlikow[100];
    int tablicaRozmiarowPlikow[100];
    int licznaPlikow= 0;


    //przesukujemy wszsytkie pliki
    przeszukiwanieFolderu(tablicaPlikow, tablicaRozmiarowPlikow, &licznaPlikow);
    //albo tylko jeden
    //tablicaPlikow[0] = "WE_NP_100000.txt";
    //tablicaRozmiarowPlikow[0] = 50000;
    //licznaPlikow=1;

    for(int k = 0; k< licznaPlikow; k++){

        rozmiar = tablicaRozmiarowPlikow[k];

        string fileName = tablicaPlikow[k].c_str();

        wczytywaniePliku1(dane, fileName, rozmiar);
        //wyswietlTablice(dane, rozmiar);

        cout << "badanie dla pliku: " << tablicaPlikow[k] << ", rozmiar tablicy:" << tablicaRozmiarowPlikow[k] << endl;


        //TEST nr 1
        kopiowanieTablicy(dane, daneKopia, rozmiar);
        pomiarCzasuStart(&begin);

        bubbleSort(daneKopia,rozmiar);

        pomiarCzasuStopIWyniki(&begin,&end);
        //wyswietlTablice(daneKopia, rozmiar);

        //TEST nr 2
        kopiowanieTablicy(dane, daneKopia, rozmiar);
        pomiarCzasuStart(&begin);

        cout << "...sortowanie przez laczenie..." << endl;
        merge_sort(daneKopia, 0, rozmiar-1);

        pomiarCzasuStopIWyniki(&begin,&end);
        //wyswietlTablice(daneKopia, rozmiar);

        //TEST nr 3
        kopiowanieTablicy(dane, daneKopia, rozmiar);
        pomiarCzasuStart(&begin);

        cout << "...sortowanie przez laczenie v2..." << endl;
        mergeSort2(daneKopia, 0, rozmiar-1);

        pomiarCzasuStopIWyniki(&begin,&end);
        //wyswietlTablice(daneKopia, rozmiar);


        //TEST nr 4
        kopiowanieTablicy(dane, daneKopia, rozmiar);
        pomiarCzasuStart(&begin);

        selectionSort(daneKopia,rozmiar);

        pomiarCzasuStopIWyniki(&begin,&end);
        //wyswietlTablice(daneKopia, rozmiar);


        //TEST nr 5
        kopiowanieTablicy(dane, daneKopia, rozmiar);
        pomiarCzasuStart(&begin);

        insertionSort(daneKopia,rozmiar);

        pomiarCzasuStopIWyniki(&begin,&end);
        //wyswietlTablice(daneKopia, rozmiar);


        //TEST nr 5
        kopiowanieTablicy(dane, daneKopia, rozmiar);
        pomiarCzasuStart(&begin);

        heapSort(daneKopia,rozmiar);

        pomiarCzasuStopIWyniki(&begin,&end);
        //wyswietlTablice(daneKopia, rozmiar);

        cout << endl;
    }


    return 0;
}
