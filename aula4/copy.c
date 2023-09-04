#include "list.h"

/* */
List* copy(List *A)
{
    /*Terminar*/
    
}

/* */
int main()
{
    int k;
    List *A = NULL;
    for (k = 10; k >= 0; k -= 2)
        A = insert(A, k);
    print(A);
    List *B = copy(A);
    print(B);
    destroy(A);
    print(B);
    return 0;
}
