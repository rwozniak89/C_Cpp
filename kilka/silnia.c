#include <stdio.h>
#include <stdlib.h>
/*
S³owo rekurencja (równie¿ rekursja) wywodzi siê z jêzyka ³aciñskiego - recurrere  = biec z powrotem.
 
W algorytmice mówimy, ¿e dany algorytm jest rekurencyjny, jeœli do rozwi¹zania pewnego problemu 
wykorzystuje on sam siebie.
 
W programowaniu dana funkcja jest rekurencyjna, jeœli wywo³uje sam¹ siebie. 

Kolejne wywo³ania takiej funkcji nazywamy rekurencyjnym ci¹giem wywo³añ. 
Ci¹g ten nie mo¿e byæ nieskoñczony - ka¿de wywo³anie funkcji powoduje umieszczenie w pamiêci komputera 
adresu powrotu, czyli miejsca w programie, do którego wraca procesor, gdy zakoñczy wykonywaæ kod funkcji.
 
Poniewa¿ pamiêæ jest skoñczona, to nie mo¿na w niej umieœciæ nieskoñczenie wiele adresów powrotnych. 
Dlatego w rekurencji bardzo wa¿ne jest okreœlenie warunku, 
który koñczy rekurencjê - np. funkcja przestaje ju¿ dalej wywo³ywaæ sam¹ siebie.
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
