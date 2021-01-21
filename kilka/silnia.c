#include <stdio.h>
#include <stdlib.h>
/*
S�owo rekurencja (r�wnie� rekursja) wywodzi si� z j�zyka �aci�skiego - recurrere  = biec z powrotem.
 
W algorytmice m�wimy, �e dany algorytm jest rekurencyjny, je�li do rozwi�zania pewnego problemu 
wykorzystuje on sam siebie.
 
W programowaniu dana funkcja jest rekurencyjna, je�li wywo�uje sam� siebie. 

Kolejne wywo�ania takiej funkcji nazywamy rekurencyjnym ci�giem wywo�a�. 
Ci�g ten nie mo�e by� niesko�czony - ka�de wywo�anie funkcji powoduje umieszczenie w pami�ci komputera 
adresu powrotu, czyli miejsca w programie, do kt�rego wraca procesor, gdy zako�czy wykonywa� kod funkcji.
 
Poniewa� pami�� jest sko�czona, to nie mo�na w niej umie�ci� niesko�czenie wiele adres�w powrotnych. 
Dlatego w rekurencji bardzo wa�ne jest okre�lenie warunku, 
kt�ry ko�czy rekurencj� - np. funkcja przestaje ju� dalej wywo�ywa� sam� siebie.
*/

/*
	n! = 1 dla n==0
	lub  n*(n-1)!
	czyli np.:
	5! = 5*4! = 5*4*3! =5*4*3*2! = 5*4*3*2*1! = 5*4*3*2*1*0!
*/

unsigned silnia(unsigned n)
{
    if(n == 0) return 1;
    else       return n * silnia(n - 1);
}

int main()
{
    unsigned n;

    printf("Podaj liczbe naturalna aby obliczyc jej silnie \n");
    scanf("%d",&n);
    printf("%d! = %d", n, silnia(n));
    printf(" \n");
    system("PAUSE");	
    return 0;
}
