#include <iostream>
#include <fcntl.h>
#include <io.h> 

struct T_student 
{ 
	char nazwisko[5] = "imie"; 
	char imie[10]="nazwisko"; 
	int wiek; 
}; 

int main(int argc, char** argv) {
	printf("Przyklad nr 1 - Oliwia Grelewska\n"); // wydruk
	int plik; 
	char tekst[] = "To jest tekst zapisywany i odczytywany z pliku... Oliwia jest SuperXD "; 
	char znak; 
	plik = open( "test.dat", O_CREAT | O_RDWR ); 
	write( plik, tekst, strlen( tekst ) ); // zapis zawartosci tekstu do pliku 
	lseek( plik, 0L, SEEK_SET ); // przesuniecie wskaŸnika na poczatek 
	do 
	{ // odczyt po jednym znaku a¿ do napotkania eof 
		read( plik, &znak, 1); ;
		printf("%c", znak); // wydruk odczytanego znaku na ekranie 
	} while ( !eof( plik ) ); 
	close( plik ); 
	
	
	printf("\n\nPrzyklad nr 2 - Oliwia Grelewska\n\n"); // wydruk
	FILE *plik2; // utworzenie pliku binarnego z mo¿liwoscia aktualizacji 
	plik2 = fopen( "wyniki.dat", "w+b" ); 
	if( plik2 == NULL ) // kontrola b³êdów we/wy 
	{ 
		printf( "Blad otwarcia pliku wyników" ); 
		return -1; 
	} 
	fclose(plik2); // zamkniêcie wskazanego strumienia 
	//fcloseall(); // zamkniêcie wszystkich strumieni   
	
	
	printf("\n\nPrzyklad nr 3 - Oliwia Grelewska\n\n"); // wydruk
	FILE *strumien; 
	int rozmiar=3;
	T_student baza[rozmiar]; 
	baza[0].wiek= 11;
	baza[1].wiek= 12;
	baza[2].wiek= 13;
	baza[3].wiek= 13;
	baza[4].wiek= 13;
	if ( (strumien = fopen( "test.bin" , "wb" ) ) != NULL ) 
	{ // zapis zawartoœci calej bazy ( tablicy struktur) do pliku binarnego 
		fwrite( baza, sizeof(T_student), rozmiar , strumien); 
		fclose( strumien ); 
	} 
	if ( (strumien = fopen( "test.txt" , "wt" ) ) != NULL ) 
	{ // zapis zawartoœci calej bazy ( tablicy struktur) do pliku tekstowego 
		for( int i = 0; i < rozmiar; i++ ) {
			fprintf ( strumien, "%s %s %d \n", baza[i].nazwisko, baza[i].imie, baza[i].wiek ); 
		}
		fclose( strumien ); 
	} 
	
	return 0;
	system("pause");
}
