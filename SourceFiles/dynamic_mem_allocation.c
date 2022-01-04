#include <stdio.h>
#include <stdlib.h>

int main() {
    // malloc returns a void * so type cast to int* in cpp code.
    int *p = malloc(sizeof(int));
    *p = 5;
    printf("%d\n", *p);
    // after doing this p will be pointing to invalid address.
    // thats why point p to NULL after freeing.
    free(p);
    p = NULL;
    return 0;
}