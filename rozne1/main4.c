#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,d,q,r; //wprowadzamy dzieln¹, dzielnik, iloraz, resztê
	
	printf("Wprowadz dzielna (pamietaj, ze liczba musi byc calkowita)\n");
	scanf("%d", &a);
		if(a>0)
		{ 
		printf("Wprowadz dzielnik (pamietaj, ze liczba musi byc mniejsza od dzielnej)");
		scanf("%d", &d);
		bool warunek;
		warunek=(d<a);
			if(warunek, d>0)
			{
				int a=wynik;
				int licznik;
				for(licznik=0, wynik=wynik-&d, licznik++);
			}
			else if (warunek, d>0)
			{
				int a=wynik;
				int licznik;
				for(licznik=0, wynik=wynik+d, licznik++);
			}
		}
		else 
		{
			printf("Wprowadz dzielnik (pamietaj, ze liczba musi byc mniejsza od dzielnej)");
			scanf("%d", &d);
		}
		
	
	
	return 0;
}
