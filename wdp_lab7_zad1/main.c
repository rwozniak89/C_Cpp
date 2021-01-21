#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    odliczanie(10);

    return 0;
}

int odliczanie(int n)
{
    int a ;
    if(a==0) return 0;
    else{
        a = odliczanie(n-1);
        printf("\n%d",a);
        return a;
    }
}
