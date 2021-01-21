#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    const int size = 4;
    int T[size], s=0;
    int i;

    for(i=0; i<size; i++){
        scanf("%i", &T[i]);
        s+=T[i];

    }

    printf("%d", s);

    return 0;
}
