#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


double moje_dzielenie_przez_odejmowanie(int dzielna, int dzielnik) 
{
	//int next_calc = 0;
	//do { 
	 	//printf("START - Program do dzielnia liczb przez odejmowanie\n");
	 	
		int a = dzielna;//= 0; //deklarowanie i definiowanie dzielnej (a) wartoœci¹ 0
		int d = dzielnik; //= 0; //deklarowanie i definiowanie dzielnika (d) wartoœci¹ 0
		int q = 0; //deklarowanie i definiowanie ilorazu (q) wartoœci¹ 0
		int r = 0; //deklarowanie i definiowanie reszty (r) wartoœci¹ 0
		
		//printf("Wprowadz dzielna (pamietaj, ze liczba musi byc calkowita)\n");
		//scanf("%d", &a);

		//printf("Wprowadz dzielnik (pamietaj, ze liczba musi byc calkowita i mniejsza od dzielnej)\n");
		//scanf("%d", &d);
		
		//printf("Wyswietlenie pocz¹tkowych wartosci zmiennych: dzielna=%d, dzielnik=%d, iloraz=%d, reszta=%d\n",a,d,q,r);
		
		int wynik = a; 
		int licznik = 0; //wprowadzamy licznik, który jest iloœci¹ pêtli
		if(a>0)
		{
			//printf("Dzielna jest wieksza od zera\n");
			if(d>0)
			{
				//printf("Dzielnik jest wiekszy od zera\n");
				while(wynik>=0)
				{
					wynik=wynik-d;
					licznik++;
				}
				if(wynik != 0) 
				{
					r = wynik+d;
				}
				q = licznik-1;
			}
			else if(d<0)
			{
				//printf("Dzielnik jest mniejszy od zera\n");
				while(wynik>=0)
				{
					wynik=wynik+d;
					licznik++;
				}
				if(wynik != 0) 
				{
					r = wynik-d;
				}
				q = (licznik-1) * (-1);
				
			}
			else
			{
				//printf("Dzielnik jest rowny zero\n");
			}
		}
		else if(a<0)
		{
			//printf("Dzielna jest mniejsza od zera\n");
			if(d>0)
			{
				//printf("Dzielnik jest mniejszy od zera\n"); 
				while(wynik<0)
				{
					wynik=wynik+d;
					licznik++;
				}
				r = wynik;
				q = licznik * (-1);
			}
			else if(d<0)
			{
				//printf("Dzielnik jest mniejszy od zera\n");
				while(wynik<0)
				{
					wynik=wynik-d;
					licznik++;
				}
				r = wynik;
				q = licznik;
				
			}
			else
			{
				//printf("Dzielnik jest rowny zero\n");
			}
		}
		else
		{
			//printf("Dzielna jest rowna zero\n");
		}
		//printf("---------------KONIEC------------------");
		//printf("Wyswietlenie wybikowych wartosci zmiennych: \ndzielna=%d\ndzielnik=%d\niloraz=%d\nreszta=%d\n",a,d,q,r);
		//printf("q: %d, r: %d", q, r);
		
		wynik = a;
		licznik = 0;
		int ile_na_minusie = 0;
		if(a<0)
		{
			ile_na_minusie++;
			a = a* (-1);
		}
		if(d<0)
		{
			ile_na_minusie++;
			d = d* (-1);
		}
		while(wynik>=0)
		{
			wynik=wynik-d;
			licznik++;
		}
		if(wynik != 0) 
		{
			r = wynik+d;
		}
		q = licznik-1;
		double nowyWynik = (double)q + (double)r/d;
		if (ile_na_minusie == 1) nowyWynik = nowyWynik*(-1);
		return nowyWynik;
		
		//printf("\nPonowna kalkulacja? TAK - wcisnij 0; NIE - wcisnij inny klawisz \n");
		//scanf("%d",&next_calc);
    //}
    //while (next_calc == 0);
    
	//system("PAUSE");
	//return 0;
}

int main (){
	
	double wyniczek = moje_dzielenie_przez_odejmowanie(7,3);
	
	printf("%f\n", wyniczek);
	
	wyniczek = moje_dzielenie_przez_odejmowanie(7,-3);
	printf("%f\n", wyniczek);
	
	wyniczek = moje_dzielenie_przez_odejmowanie(-7,3);
	printf("%f\n", wyniczek);
	
	wyniczek = moje_dzielenie_przez_odejmowanie(-7,-3);
	printf("%f\n", wyniczek);
	
	system("PAUSE");
	return 0;
}
	

