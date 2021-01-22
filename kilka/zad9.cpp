#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int *wskaznik;
	int k = 10;
	wskaznik = &k;
	
	printf("Zmienna k = %d\n", k);
	printf("Adres na ktory wskazuje wskaznik = %p\n", &wskaznik);
	printf("Wartosc wskazywana przez wskaznik = %d\n", *wskaznik);
	printf("Adres zmiennej k = %p\n", &k);
	
	k = 11;
	printf("Zmienna k = %d\n", k);
	printf("Adres na ktory wskazuje wskaznik = %p\n", &wskaznik);
	printf("Wartosc wskazywana przez wskaznik = %d\n", *wskaznik);
	printf("Adres zmiennej k = %p\n", &k);
	
	*wskaznik = 12;
	printf("Zmienna k = %d\n", k);
	printf("Adres na ktory wskazuje wskaznik = %p\n", &wskaznik);
	printf("Wartosc wskazywana przez wskaznik = %d\n", *wskaznik);
	printf("Adres zmiennej k = %p\n", &k);
	
	
	return 0;
}
