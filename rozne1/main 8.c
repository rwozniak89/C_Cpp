#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	printf("Wprowadz dzielna (pamietaj, ze liczba musi byc calkowita)\n");
	int a = 0; //deklarowanie i definiowanie dzielnej (a) warto�ci� 0
	scanf("%d", &a);
	
	printf("Wprowadz dzielnik (pamietaj, ze liczba musi byc calkowita i mniejsza od dzielnej)\n");
	int d = 0; //deklarowanie i definiowanie dzielnika (d) warto�ci� 0
	scanf("%d", &d);
	
	int q = 0; //deklarowanie i definiowanie ilorazu (q) warto�ci� 0
	int r = 0; //deklarowanie i definiowanie reszty (r) warto�ci� 0
	
	printf("Wyswietlenie wartosci zmiennych: \ndzielna=%d\ndzielnik=%d\niloraz=%d\nreszta=%d\n",a,d,q,r);
	
		if(a>0)
		{
			printf("Dzielna jest wieksza od zera\n");
			if(d>0)
			{
				printf("Dzielnik jest wiekszy od zera\n");
				int wynik = a; 
				int licznik = 0; //wprowadzamy licznik, kt�ry jest ilo�ci� p�tli
				while(wynik>=0)
				{
					wynik=wynik-d;
					licznik++;
				}
				r = wynik+d;
				q = licznik-1;
			}
			else if(d<0)
			{
				printf("Dzielnik jest mniejszy od zera\n");
				int wynik = a; 
				int licznik = 0; 
				while(wynik>=0)
				{
					wynik=wynik+d;
					licznik++;
				}
				r = wynik-d;
				q = licznik-1;
			}
			else if(d==0)
			{
				printf("Dzielnik jest rowny zero\n");
				printf("Wprowadzono niepoprawne dane\n");
			}
		}
		else if(a<0)
		{
			printf("Dzielna jest mniejsza od zera\n");
			if(d>0)
			{
				printf("Dzielnik jest wiekszy od zera\n");
				int wynik = a; 
				int licznik = 0; 
				while(wynik>=0)
				{
					wynik=wynik+d;
					licznik++;
				}
				r = wynik;
				q = licznik*(-1);
			}
			else if(d<0)
			{
				printf("Dzielnik jest mniejszy od zera\n");
				int wynik = a; 
				int licznik = 0; 
				while(wynik>=0)
				{
					wynik=wynik-d;
					licznik++;
				}
				r = wynik;
				q = licznik;
			}
			else if(d==0)
			{
				printf("Dzielnik jest rowny zero\n");
				printf("Wprowadzono niepoprawne dane\n");
			}
		}
		else if(a==0)
		{
			printf("Dzielna jest rowna zero\n");
			printf("Wprowadzono niepoprawne dane\n");
		}
	
	printf("Wyswietlenie wartosci zmiennych:");
	printf("\ndzielna=%d\ndzielnik=%d\niloraz=%d\nreszta=%d\n",a,d,q,r);
	system("PAUSE");
	return 0;
}
	

