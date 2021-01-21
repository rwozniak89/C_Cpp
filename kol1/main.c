#include <stdio.h>
#include <stdlib.h>


void switch_numbers(int ** a, int ** b){
  int * tmp;
  *tmp = *a;
  *a = *b;
  *b = *tmp;
}

int main()
{
  int a = 5;
  int b = 10;

  printf("a: %d, b: %d\n", a, b);
  switch_numbers(&a, &b);

  printf("a: %d, b: %d\n", a, b);

  return 0;
}
