 #include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ZAD3
//napisz program, ktory wypisze 1, gdy dokladnie dwie z trzech podanych liczb calkowitych maja taka sama wartosc,
//natomiast wartosc zero, jest wypisywana w przeciwym przypadku.
int main() {
	int liczba1;
	int liczba2;
	int liczba3;
	printf("Program wypisze 1, gdy co najmniej dwie z trzech podanych liczb calkowitych beda miec taka sama wartosc.\nW innym przypadku program wypisze 0.\n");
	printf("Pierwsza liczba: ");
	scanf("%d", &liczba1);
	printf("Druga liczba: ");
	scanf("%d", &liczba2);
	printf("Trzecia liczba: ");
	scanf("%d", &liczba3);
	if(liczba1 == liczba2 || liczba2 == liczba3 || liczba3 == liczba1){
		printf("1");
	}
	else if(liczba1 == liczba2 == liczba3){
		printf("0");
	}
	else{
		printf("0");
	}
	return 0;
}
