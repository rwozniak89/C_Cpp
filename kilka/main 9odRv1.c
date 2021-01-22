#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int next_calc = 0;
	do { 
        
		printf("Wprowadz dzielna (pamietaj, ze liczba musi byc calkowita)\n");
		int a = 0; //deklarowanie i definiowanie dzielnej (a) wartoœci¹ 0
		scanf("%d", &a);
		
		printf("Wprowadz dzielnik (pamietaj, ze liczba musi byc calkowita i mniejsza od dzielnej)\n");
		int d = 0; //deklarowanie i definiowanie dzielnika (d) wartoœci¹ 0
		scanf("%d", &d);
		
		int q = 0; //deklarowanie i definiowanie ilorazu (q) wartoœci¹ 0
		int r = 0; //deklarowanie i definiowanie reszty (r) wartoœci¹ 0
		
			if(a>0)
			{
				printf("Dzielna jest wieksza od zera\n");
				if(d>0)
				{
					printf("Dzielnik jest wiekszy od zera\n");
					int wynik = a; 
					int licznik = 0; //wprowadzamy licznik, który jest iloœci¹ pêtli
					while(wynik>=0)
					{
						wynik=wynik-d;
						licznik++;
					}
					if(wynik == 0) 
					{
						r = 0;
					}
					else
					{
						r = wynik+d;
					}
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
					if(wynik == 0) 
					{
						r = 0;
					}
					else
					{
						r = wynik-d;
					}
					
					q = (licznik-1) * (-1);
				}
				else
				{
					printf("Dzielnik jest rowny zero\n");
				}
			}
			else if(a<0)
			{
				printf("Dzielna jest mniejsza od zera\n");
				if(d>0)
				{
					printf("Dzielnik jest mniejszy od zera\n");
					int wynik = a; 
					int licznik = 0; 
					while(wynik<=0)
					{
						wynik=wynik+d;
						licznik++;
					}
					r = wynik;
					q = licznik * (-1);
				}
				else if(d<0)
				{
					printf("Dzielnik jest mniejszy od zera\n");
					int wynik = a; 
					int licznik = 0; 
					while(wynik<=0)
					{
						wynik=wynik-d;
						licznik++;
					}
	
					r = wynik;
					q = licznik;
				}
				else
				{
					printf("Dzielnik jest rowny zero\n");
				}
			}
			else
			{
				printf("Dzielna jest rowna zero\n");
			}
		
		printf("Wyswietlenie wartosci zmiennych:");
		printf("\ndzielna=%d\ndzielnik=%d\niloraz=%d\nreszta=%d\n",a,d,q,r);
	
		printf("Ponowna kalkulacja? TAK - wcisnij 0; NIE - wcisnij inny klawisz \n");
		scanf("%d",&next_calc);
    }
    while (next_calc == 0);
	system("PAUSE");
	return 0;
}
	

