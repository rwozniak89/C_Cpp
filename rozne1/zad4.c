#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ZAD4
//napisz program, ktory oblicza sume wszystkich liczb naturalnych mniejszych lub rownych podanej liczbie.
int main() {
	float twojaLiczba;
	float pierwszyWyraz = 0;
	float liczbaWyrazow =0;
	float suma = 0;
	printf("Program obliczy sume wszystkich liczb naturalnych mniejszych lub rowynch podanej liczbie.\n");
	printf("Twoja liczba: ");
	scanf("%f", &twojaLiczba);
	if( twojaLiczba < 0){
		printf("Niepoprawna liczba. Ujemna liczba nie zawiera sie w zbiorze liczb naturalnych.\n");
		return 0;
	}
	liczbaWyrazow = (twojaLiczba+1);
	suma = ((pierwszyWyraz + twojaLiczba)/2) * liczbaWyrazow;
	printf("Suma wszystkich liczb naturalnych mniejszych lub rownych %0.f to %.0f", twojaLiczba, suma);
	
	
	return 0;
} 
