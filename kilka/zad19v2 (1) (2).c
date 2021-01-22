#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ZAD19
// Napisz program, który zapisujê znaki wprowadzone za pomoc¹ klawiatury do pliku. 
//U¿ytkownik powinien mieæ mo¿liwoœæ wyboru, czy ma nadpisaæ plik nowym tekstem lub dopisaæ tekst na koniec do pliku (bez usuwania poprzedniej wartoœci)

int main() {
	int menu;
	FILE *plik; //tworzê wskaŸnik, który pokazuje na nasz plik
	printf("Chcesz nadpisac plik nowym tekstem (1), czy dopisac tekst na koniec pliku (2)? Wybierz opcje 1-2.\nTwoj wybor: ");
	scanf("%d", &menu);
	if(menu != 1 && menu != 2)
	{
		printf("Wprowadzono bledna pozycje. Prosze wybrac opcje 1-2\n");
		system("pause");
	}
	switch (menu){
		case 1:
			plik = fopen("plik.txt", "w"); // otwieram plik i poprzez literkê "w" (skrót od write) sygnalizujê, ¿e mam zamiar zapisywaæ do pliku
			printf("Wprowadz tekst, ktory chcesz nadpisac: ");
			break;
		case 2:
			plik = fopen("plik.txt", "a"); // "a" to skrót od append - dopisywanie danych do pliku
			if(plik == NULL) return 1; // je¿eli nie ma utworzonego wczeœniej pliku program zwraca 1
			printf("Wprowadz tekst, ktory chcesz dopisac: ");
			break;
	}
	char twojTekst[100];
	scanf("%s", &twojTekst);
	fprintf(plik,"\n%s", twojTekst);	// zapisuje do pliku nasz tekst
	fclose(plik); // fclose zamyka plik. Jest to komenda konieczna, poniewa¿ jeœli jej nie wykonamy to stracimy wszystkie do tej pory zapisane dane
	if(menu == 1)
	{
		printf("Utworzono plik z tekstem: %s", twojTekst);		
	}
	else if(menu == 2)
	{
		printf("Tekst dopisany do istniejacego pliku: %s", twojTekst);
	}

	return 0;
}
