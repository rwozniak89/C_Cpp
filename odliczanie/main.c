#include <stdio.h>
#include <stdlib.h>


int odliczanie(int n)
{

    int a = n;
    if(a==0) return 1;
    odliczanie(n-1);
    //printf("-----------%d\n",a);
    if(a%2==1 || a%3==0){
        printf("%d,",a);
    }
    return a;

}

int odlicz (int n)
{
    int i;
    if(n==0) return 0;

    odlicz(n-1);

    if(n%2==1 || n%3 == 0)
    {
        printf("%d,", n);
    }

    //printf("%d", odlicz(n-1));

}

int potegaRek(int n, int m)
{

    if(m == 0) return 1;

    return  n = n*potegaRek(n,--m);
}

int main()
{
    printf("Hello world!\n");
    //odliczanie(22);
    odlicz(22);

    //printf("%d", potegaRek(2,10));
    return 0;
}
