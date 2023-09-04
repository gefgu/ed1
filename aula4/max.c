#include "list.h"
#include <time.h>

/* */
int max(List *l)
{
    int max;
    max = l->data;
    List *t = l->next;
    for (; t != NULL; t = t->next) {
        if(t->data > max) max = t->data;
    }
    return max;
}

/* */
int main()
{
    srand(time(NULL));
    int i;
    List *A = NULL, *B = NULL;
    for (i = 0; i < 10; i++)
        A = insert(A, rand() % 50);
    print(A);
    printf("Max: %d\n", max(A));

    return 0;
}
