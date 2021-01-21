#include <stdio.h>
#include <stdlib.h>




int funkcja(int a, int b, int c){

    int x;
    return x=a+b+c;
}

int rek(int max){

    if(max == 2){
        printf("%d", max);
        return 2;
    }
    else if ((max%2==0) || (max>10 && max%3 ==0))
    {
         printf("%d\n", max);


    }
      return rek(max -1);

}

int prostaChoinka(int n){

    if(n<=0) return 0;
    int i;

    for(i=n;i>0;i--){
        printf("*");
    }
    printf("\n");

    prostaChoinka(n-1);




}

int ciagFibb(int n){

    if(n<=0) return 0;
    if(n==1) return 1;


    return ciagFibb(n-1) + ciagFibb(n-2);




}


int main()
{
    printf("Hello world!\n");

    prostaChoinka(5);


    int wynik = ciagFibb(6);
    printf("%d",wynik);

    return 0;
}
