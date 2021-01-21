#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a;
    int *b;
    a=3;
    b=&a;

    printf("Wartosc zmiennej:%d\n", a);
    printf("Adres zmiennej:%d\n", &a);
    printf("Adres na ktory wskazuje wskaznik:%d\n", b);
    printf("Wartosc wskazywana przez wskaznik: %d\n\n", *b);

    return 0;
}
