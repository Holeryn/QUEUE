#include <stdio.h>
#include "queue.h"

int main(void)
{
    queue q;
    Item i;

    q = create();

    push(q,10);
    push(q,20);
    push(q,30);
    push(q,40);
    pop(q);

    i = return_first(q);
    printf(" %d ",i);

    i = return_last(q);
    printf(" %d ",i);

    destroy(q);
}