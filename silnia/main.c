#include <stdio.h>
#include <stdlib.h>

int silnia (int a)
{
    int wynik =1;

    if (a==1)
    {
        wynik = 1;
        //return 1;
    }
    else{
        //silnia(a) = silnia(a) * silnia(a-1);
        //return a * silnia(a - 1);
        wynik = a * silnia(a - 1);
    }
    return wynik;
}

int silnia2 (int a)
{

    if (a==0)
    {
        return 1;
    }
    else{
        //silnia(a) = silnia(a) * silnia(a-1);
        //return a * silnia(a - 1);
        return a * silnia(a - 1);
    }

}


int f(){


    int T[]= {1,2,3,4,5,6,7};
    int n = 7;

    if(n%2==0){
        printf("\n%d", (T[n/2-1] + T[n/2])/2);
    }
    else
    {
        printf("\n%d", T[(n/2)-1]);

    }
}

int liczba_trojkatna(int n)
{

    //int n;
    if(n>0){
    //    return (n(n+1)/2);
    }
    else {
   //         return 0;
    }
    //return liczba_trojkatna(n)
}

int func(int n)
{

    if(n<1){
        return 0;
    }
    else {
            printf("%d", n);
            return func(n-1);
    }

}

int func2(int a)
{

    if(a == 0){
            printf("%d", a);
        return 0;
    }
     if(a >0) {
            printf("%d", a);
            return func(a-1);
    }

    else {
           return 0;
    }

}

int func3(int a)
{

    if(a>1){
        printf("%d", func3(a-1));
    }

}


int main()
{
    printf("Hello world!\n");
    //int a = silnia2(5);
    //printf("%d", a);

    func3(5);

     //printf("\n\n%d", func(4));


    return 0;
}

