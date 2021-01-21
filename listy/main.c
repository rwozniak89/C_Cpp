#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int wartosc;
    struct lista* nast;
} lista;

void wyswietl(lista* pierwszy)
{
    lista* obecny = pierwszy;
    printf("List: ");
    while(obecny != NULL)
    {

        printf("%d, ", obecny->wartosc);
        obecny = obecny->nast;
    }
    printf("\n");
}

void wyswietl2(struct lista list)
{

    printf("%d ", list.wartosc);
    if(list.nast!=NULL)
        wyswietl2(*(list).nast);

    /*if(list.wartosc == NULL)
    {
        printf("pusto: ");

    }
    else
    {
        while(list.wartosc != NULL)
        {
           printf("%d ", list.wartosc);
           list = *list.nast;
            //list.wartosc = list.nast;
        }
    }*/

}

void dodaj_poczatek(lista** pierwszy, int wartosc)
{
    lista* nowy;
    nowy = malloc(sizeof(lista));
    nowy->wartosc = wartosc;
    nowy->nast = *pierwszy;
    *pierwszy = nowy;
}

void dodaj_koniec(lista* pierwszy, int wartosc)
{
    lista* nowy = pierwszy;
    while(nowy->nast != NULL)
    {
        nowy = nowy->nast;
    }
    nowy->nast = malloc(sizeof(lista));
    nowy->nast->wartosc = wartosc;
    nowy->nast->nast = NULL;
}

int usun(lista** pierwszy, int wartosc)
{
    lista *obecny;
    lista *poprzedni;

    if((*pierwszy)->wartosc == wartosc)
    {
        obecny = (*pierwszy)->nast;
        poprzedni = (*pierwszy)->wartosc;
        free(*pierwszy);
        *pierwszy = obecny;
        return;
    }

    poprzedni = obecny = (*pierwszy)->nast;
    while(obecny)
    {
        if(obecny->wartosc == wartosc)
        {
            poprzedni->nast = obecny->nast;
            free(obecny);
            return;
        }
        poprzedni = obecny;
        obecny = obecny->nast;
    }
    return;
}

int main()
{
    lista* pierwszy;
    pierwszy = malloc(sizeof(lista));
    pierwszy->wartosc = 3;
    pierwszy->nast = malloc(sizeof(lista));
    pierwszy->nast->wartosc = 4;
    pierwszy->nast->nast = NULL;

        wyswietl(pierwszy);
    dodaj_koniec(pierwszy, 5);
    dodaj_koniec(pierwszy, 6);
        wyswietl(pierwszy);
    dodaj_poczatek(&pierwszy, 2);
        wyswietl(pierwszy);
    dodaj_poczatek(&pierwszy, 1);
        wyswietl(pierwszy);
    usun(&pierwszy, 4);
    wyswietl(pierwszy);
    wyswietl2(*pierwszy);
}
