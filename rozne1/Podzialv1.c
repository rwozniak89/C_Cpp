#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int iloczyn (int x, int y)
{
  int iloczyn_xy;
  iloczyn_xy = x*y;
  return iloczyn_xy;
}

float moje_minimum (float x, float y)
{
  if(x<y) return x;
  else return y;
}

float moje_maximum (float x, float y)
{
  if(x>y) return x;
  else return y;
}


double moje_dzielenie_przez_odejmowanie(int dzielnik, int dzielna) 
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
				//printf("Dzielnik jest mniejszy od zera\n");
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
		double iloraz = (double)q;
		if(r != 0 && q != 0)
		{
			double reszta = 0.0;
			reszta = r/iloraz;
			return iloraz + reszta;
		}
		return iloraz; 
		
		//printf("\nPonowna kalkulacja? TAK - wcisnij 0; NIE - wcisnij inny klawisz \n");
		//scanf("%d",&next_calc);
    //}
    //while (next_calc == 0);
    
	//system("PAUSE");
	//return 0;
}

int moje_potegowanie (int potega, int liczba)
{
	if(potega >=0){
		int wynik = liczba;
		while(potega>1){
			wynik = wynik * liczba;
			potega--;
		}
		return wynik;
	}
	else if(potega < 0){
		return -1;
	}
	else {
		return 1;
	}
}

int main()
{
     int         POD;       // deklaracja zmiennej na dana wejsciowa poziomu podzia³u
     /*
       deklaracja zmiennych na:
                  dane wejsciowe: definiujace prostokat w kartezianskim ukladzie wspolrzednych
                                  za pomoca przciwleglych wierzcholkow (XLD,YLD,XPG,YPG)
                  dane robocze: dlugosci bokow najmniejszych prostokatow wynikajacych z poziomu podzialu (DX, DY)
                                lewych dolnych wierzcholkow najmniejszych prostokatow wynikajacych z poziomu podzialu (X, Y)
                                       i nie tylko w tym celu
                                decyzja o ponownych obliczeniach (next_calc)
     */
     float       XLD,YLD,XPG,YPG,DX,DY,X,Y;
     int         next_calc;

    do { 
        next_calc = 1;
        printf("Podaj wspolrzedna x dolnego lewewego wierzcholka prostokata\n");
        scanf("%f",  &XLD);
        printf("Podaj wspolrzedna y dolnego lewego wierzcholka prostokata \n");
        scanf("%f",  &YLD);
        printf("Podaj wspolrzedna x gornego prawego wierzcholka prostokata \n");
        scanf("%f",  &XPG);
        printf("Podaj wspolrzedna y gornego prawego wierzcholka prostokata \n");
        scanf("%f",  &YPG);
        printf("Podaj poziom podzialu \n");
        scanf("%d",&POD);
        if((XLD != XPG) && (YLD != YPG) && (POD >= 0)) // walidacja ok. - liczymy
        {
                // normalizacja
            X = XLD;
            Y = YLD;
            XLD = moje_minimum(XLD, XPG);
            YLD = moje_minimum(YLD, YPG);
            XPG = moje_maximum(X, XPG);
            YPG = moje_maximum(Y, YPG);
                // liczymy boki najmniejszych prostokatow
        	DX = moje_dzielenie_przez_odejmowanie( (XPG - XLD) , (moje_potegowanie(POD,2)) );
            //DX = (XPG - XLD) / (moje_potegowanie(POD,2));
            DY = (YPG - YLD) / (moje_potegowanie(POD,2));
               //  ustawienie lewego dolnego wierzcholka prostokata bazowego
            X = XLD;
            Y = YLD;
              // wyznaczanie wierzcholkow prostokatow wynikajacych z podzialu
            do {    // petla po Y
                while (X < XPG)  // petla po X
                {
                         // wyprowadzenie wynikow kalkulacji
                      printf("%f  %f  %f  %f", X, Y, X + DX, Y + DY);
                      printf(" \n");
                      X = X + DX;
                }
                X = XLD;
                Y = Y + DY;
            }
            while (Y < YPG);
        }
        else    // wynik walidacji wprowadzonych danych negatywny
        {
            printf("Wprowadzono nieporawne dane \n");
        }
        printf("Ponowna kalkulacja? TAK - wcisnij 0; NIE - wcisnij inny klawisz \n");
        scanf("%d",&next_calc);
    }
    while (next_calc == 0);
    
    system("PAUSE");	
    return 0;
}




