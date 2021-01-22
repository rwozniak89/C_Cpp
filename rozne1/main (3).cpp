#include <iostream>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//kod do opcji 1 - suma ciagu arytmetycznego 
int oblicznieNwyrazu(int a1, int r, int n){
    if (n == 1)
    {

        return a1;
    } 
    else 
    {
    
        return r + oblicznieNwyrazu(a1, r, n - 1);
    }
}

int sumaNwyrazow(int a1, int r, int n){
  return (a1 + oblicznieNwyrazu(a1, r, n))*(n/2)*n;
}
 
int funkcjaGlownaCiagu() {
	
	int a1=0; //pierwszy wyraz ci¹gu
	int R=0; //ró¿nica
	int n=0; //iloœæ elementów ci¹gu
	
	printf("Podaj pierwszy wyraz ciagu arytmetycznego:\n");
	scanf("%d", &a1);
	printf("Podaj roznice ciagu arytmetycznego:\n");
	scanf("%d", &R);
	printf("Podaj ilosc elementow ciagu arytmetycznego:\n");
	scanf("%d", &n);
	printf("Pierwszy wyraz ciagu (a1): %d\nRoznica (R): %d\nIlosc elementow ciagu (n): %d\n",a1,R,n);
	printf("obliczanieSumyCiaguArytm dla a1=%d, r=%d, n=%d to: %d\n", a1, R, n, sumaNwyrazow(a1,R,n));
    printf("obliczanie ostatniego wyrazu ciagu dla a1=%d, r=%d, n=%d to: %d\n", a1, R, n, oblicznieNwyrazu(a1,R,n));

	return 0;
}



//kod do opcji 2 - silnia
unsigned silnia(unsigned n)
{
    if(n == 0) return 1;
    else       return n * silnia(n - 1);
}

int silniaprogram()
{
    unsigned n;

    printf("Podaj liczbe naturalna aby obliczyc jej silnie: ");
    scanf("%d",&n);
    printf("%d! = %d", n, silnia(n));
    printf(" \n");
    system("PAUSE");	
    return 0;
}

//kod do opcji 3 - pierwiastek stopnia drugiego
int funkcjaGlownaPierwiastek()
{
    int liczba, wynik;
	printf("Wprowadz liczbe: ");
    scanf("%d", &liczba);
    wynik = sqrt(liczba);
	printf("Pierwiastek stopnia drugiego z liczby %d to %d\n", liczba, wynik);
    system("PAUSE");

    return 0;
}

//kod do opcji 4 - parametr BMI
int glownaFunkcjaBMI() 
{
	float waga=0;
    float wzrost=0;
	float bmi;
    printf("Podaj swoja wage w [kg]: ");
    scanf("%f", &waga);
    if(waga == 0)
    {
    	printf("Wpisales/as niepoprawna wartosc");
    	return 0;
	}
    printf("Podaj swoj wzrost w [m]: ");
    scanf("%f", &wzrost);
     if(wzrost == 0)
    {
    	printf("Wpisales/as niepoprawna wartosc");
    	return 0;
	}
    printf("Podales wage: %.2f, wzrost: %.2f", waga, wzrost);
    bmi = waga /( wzrost * wzrost );
    printf("\nTwoje bmi wynosi: %.2f", bmi);
    printf("\nKomentarz odnosnie twojej wagi: \n");
    if(bmi <= 15.0)
    {
    	printf("Wyglodzenie. Konieczna hospitalizacja - jest to bezposrednie zagrozenie zycia.");
	}
	else if(bmi > 15.1 && bmi <= 16.6)
	{
		printf("Wychudzenie (spowodowane zwykle przez ciezka chorobe lub anoreksje). Konieczna jest pomoc specjalisty!");
	}
	else if(bmi > 16.7 && bmi <= 18.5)
	{
		printf("Niedowaga. Wazysz zbyt malo. Na pewno nie powinienes korzysztac z zadnej diety! Uwaga: niedowaga moze byc objawem powaznych chorob,\nw tym chorob nowotworowych, pasozytniczych. Moze rowniez byc objawem i skutkiem chorob psychicznych typu anoreksja i bulimia.");
	}
	else if(bmi > 18.6 && bmi <= 24.9)
	{
		printf("Wartosc prawidlowa. Gratulujemy. Nie musisz korzystac z zadnej diety. Jesli mimo wszystko uwazasz, ze tu i owdzie masz za duzo ciala\n polecamy lekka diete, a w szczegolnosci cwiczenia fizyczne, np. bieganie, silownia, plywanie, gra w siatkowke.\nCwiczenia to najlepszy sposob na naturalne wymodelowanie ciala.");
	}
	else if(bmi > 25,0 && bmi <= 19,9)
	{
		printf("Okres przed otyloscia. Zacznij o siebie dbac! Skorzystaj z diety - moze to byc dieta South Beach, dieta rozdzielna czy dieta 1200 kalorii.\nI pamietaj - najlepszym sposobem na pozbycie sie zbednych kilogramow jest aktywnosc fizyczna.\nZacznij biegac, chodzic na plywalnie, silownie, w domu mozesz wykonywac polgodzinne cwiczenia fizyczne - to naprawde pomaga!");
	}
	else if(bmi > 30.0 && bmi <= 34.9)
	{
		printf(" I stopien otylosci. Byc moze potrzebna jest pomoc specjalisty. Tego typu otylosc powoduje powstanie tzw. chorob cywilizacyjnych - cukrzycy,\nchorob serca, nowotworow i innych. Zacznij o siebie dbac! Skorzystaj z diety - moze to byc dieta:\nSouth Beach, dieta rozdzielna, czy dieta kopenhaska. Najlepiej zacznij odchudzanie pod kierunkiem dietetyka - on wskaze najlepsza metode.");
	}
	else if(bmi > 35.0 && bmi <= 39.9)
	{
		printf("II stopien otylosci. Twoja waga jest zdecydowanie za duza. Najprawdopodobiej potrzebna jest pomoc specjalisty.");
	}
	else if(bmi >= 40.0)
	{
		printf("III stopien otylosci (otylosc kliniczna) - konieczna natychmiastowa pomoc specjalisty.");
	}
	
	return 0;
}

//kod do opcji 5 - przeliczanie stopni Celsjusza na Farenheit
int temperatura()
{
	int stopnie=0, wynik=0;
	printf("Podaj wartosc w stopniach Celsjusza: ");
	scanf("%d", &stopnie);
	wynik = stopnie*33,8;
	//wynik = cels_to_fahr(stopnie); 
	printf("\n%d w stopniach Celsjusza to %d w stopniach Fahrenheita\n", stopnie, wynik);
	system("PAUSE");
	
	return 0;
}

//kod do opcji 6 - szyfrowanie metoda Cezara
int funkcjaGlownaszyfrowania() {
	int i=0, ile=0;
	char tablica [100];
	printf("Ile chcesz wprowadzic znakow?\n");
	scanf("%d", &ile);
	printf("Ile = %d\n",ile);
	for(i=0; i<ile; i++)
	{
		printf("Podaj wartosc tablicy w punkcie %d:  \n",i);
		scanf("%s", &tablica[i]);
		
	}
	printf("Wyswietlenie jawnego tekstu: ");
	for(i=0; i<ile; i++)
	{
		printf("%c", tablica[i]);
	}
	printf("\n");
	int klucz;
	printf("Podaj klucz kodowania w postaci liczby przesuniecia szyfru Cezara: ");
	scanf("%d", &klucz);
	if(klucz<0)
		{
		klucz=klucz*(-1);
		}
	klucz=klucz%26;
	
	printf("Podano klucz o wartosci %d\n",klucz);
	char szyfrogram [100];
	for(i=0; i<ile; i++)
	{
	szyfrogram[i]=tablica[i]+klucz;
	}
	printf("Wyswietlenie tekstu zaszyfrowanego: ");
	for(i=0; i<ile; i++)
	{
		printf("%c", szyfrogram[i]);
	}
	printf("\n");
	char odszyfrowane[100];
	for(i=0; i<ile; i++)
	{
	odszyfrowane[i]=szyfrogram[i]-klucz;
	}
	printf("Wyswietlenie tekstu odszyfrowanego: ");
	for(i=0; i<ile; i++)
	{
		printf("%c", odszyfrowane[i]);
	}
	printf("\n");
	return 0;
}

// FUNKCJA GLOWNA
int main(int argc, char** argv) {
	printf("Witaj w programie kalkulator. Co chcesz obliczyc? (Wybierz numer od 1-5)\n");
	printf("1. suma ciagu arytmetycznego;\n2. silnia;\n3. pierwiastek stopnia drugiego;\n4. parametr BMI;\n5. przeliczanie stopni Celsjusza na Fahrenheit;\n6. szyfrowanie metoda Cezara\n");
	int opcja;
	printf("Twoj numer: ");
	scanf("%d", &opcja);
	switch(opcja)
	{
		case 1:
			printf("Wybrales/as opcje suma ciagu arytmetycznego.\n");
			funkcjaGlownaCiagu();
			break;			
		case 2:
			printf("Wybrales/as opcje silnia.\n");
			silniaprogram ();
			break;
		case 3:
			printf("Wybrales/as opcje pierwiastek stopnia drugiego.\n");
			 funkcjaGlownaPierwiastek();
			break;
		case 4:
			printf("Wybrales/as opcje parametr BMI.\n");
			 glownaFunkcjaBMI();
			break;
		case 5:	
			printf("Wybrales/as opcje przeliczanie stopni Celsjusza na Fahrenheit.\n");
			temperatura ();
			break;
		case 6:
			printf("Wybrales/as opcje szyfrowanie metoda Cezara.\n");
			funkcjaGlownaszyfrowania();
			break;
			
	}
	system("pause");
	return 0;
}



