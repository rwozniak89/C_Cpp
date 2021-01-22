#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ZAD5
////napisz program, ktory oblicza srednia dla 5 liczb naturalnych np. ocen 
//*zaimplementuj rozwiazanie z mozliwoscia podania wlasnej liczby ocen do obliczenia sredniej
int main() {
	int twojaLiczba;
	int twojeLiczby[100];
	int licznik = 0;
	float srednia = 0;
	printf("Program oblicza srednia dla podanych liczb. Wprowadz swoje liczby, aby zakonczyc wpisywanie liczb, podaj liczbe ujemna.\n");
	while(true){
		printf("Wpisz swoja liczbe: ");
		licznik +1;
		scanf("%d", &twojaLiczba);
		if (twojaLiczba < 0){
			break;
		}
		twojeLiczby[licznik] = twojaLiczba;
		licznik++;
	}
	for( int i = 0; i < licznik; i++){
		srednia = srednia + twojeLiczby[i];
		
	}
	srednia = srednia/licznik;
	printf("Srednia podanych liczb wynosi %.1f ", srednia);
	
	return 0;
}
