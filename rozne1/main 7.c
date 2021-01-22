#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	printf("Wprowadz dzielna (pamietaj, ze liczba musi byc calkowita)\n");
	int a = 0; //deklarowanie i definiowanie dzielnej (a) wartoœci¹ 0
	scanf("%d", &a);
	
	printf("Wprowadz dzielnik (pamietaj, ze liczba musi byc calkowita i mniejsza od dzielnej)\n");
	int d = 0; //deklarowanie i definiowanie dzielnika (d) wartoœci¹ 0
	scanf("%d", &d);
	
	int q = 0; //deklarowanie i definiowanie ilorazu (q) wartoœci¹ 0
	int r = 0; //deklarowanie i definiowanie reszty (r) wartoœci¹ 0
	
	printf("Wyswietlenie wartosci zmiennych:");
	printf("\na=%d\nd=%d\nq=%d\nr=%d\n",a,d,q,r);
	
	
	system("PAUSE");
	return 0;
}
	

