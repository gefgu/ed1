#include "list.h"

/* */
List *copy(List *l)
{
    List *cp = create();
    List *original = l;
    while (original != NULL)
    {
        cp = insert_back(cp, original->data);
        original = original->next;
    }
    return cp;
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
