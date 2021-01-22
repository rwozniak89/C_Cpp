#include <stdio.h>
#include <stdlib.h>

const int n =6;

struct dwieLiczby
{
    int x;
    int y;
} node;


int wypisanieTablicyQusiRekurencyjne(dwieLiczby tab[n][n], int indexI, int indexJ)
{
	if(indexI < n)
	{
		indexI++;
		while (indexJ < n) {
			printf("indexI=%d, indexJ=%d, x=%d, y=%d \n", indexI-1, indexJ, tab[indexI-1][indexJ].x, tab[indexI-1][indexJ].y);
			indexJ++;
			wypisanieTablicyQusiRekurencyjne(tab, indexI, indexJ);
		}	
	}
}

int obliczeniaWektorow(dwieLiczby tab[n][n], int a, int b)
{
	for (a=0; a< n; a++) {
		for (b=0; b< n; b++){
			float wynik = (tab[n][b].x - tab[a][b].y + tab[n][n].x - tab[a][b].y);
			printf("wartosc wektora = %f\n", wynik);
		}
	}
}

int main(int argc, char** argv) {		
	dwieLiczby tab[n][n] = { 0 };
	int a,b =0;
	for (a=0; a< n; a++) {
		for (b=0; b< n; b++) {
			tab[a][b].x = a;
			tab[a][b].y = b;
		}
	}

	int i = 0;
	int j = 0;	
	wypisanieTablicyQusiRekurencyjne(tab, i, j);
	
	printf("Oblcizanie dlugosci wektora\n");
	i = 0;
	j = 0;	
	obliczeniaWektorow(tab, i, j);
	
	return 0;
}

