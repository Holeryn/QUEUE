/*########### DICHIRAZIONI PER IL PREPROCESSORE ###########*/
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

PRIVATE void make_empty(queue s);

/*########### STRUTTUE ###########*/
struct node{
    Item data;
    struct node *next;
};

struct queue_type{
    struct node *top;
};

/*########### FUNZIONI ###########*/

/*
name : push
description : inserisce un valore (n) nel queue
type : public
parameters = queue (q), Item (n) - il valore da inserire 
return = queue
*/
PUBLIC void push(queue q,Item n)
{
    struct node *new_node = malloc(sizeof(queue));
    
    if(new_node == NULL)
        printf("ERRORE + %d",__LINE__);
    
    new_node->data = n;
    new_node->next = q->top;
    q->top = new_node;
}

/*
name : pop
description : rimuove un valore dalla coda
type : public
parameters = queue (n)
return = none (void)
*/
PUBLIC void pop(queue q)
{
    if(!is_empty(q)){
        struct node *new_node;
        new_node = malloc(sizeof(queue));

        new_node->next = q->top->next;
        free(q->top);
        q->top = new_node->next;
    }else
        printf("ERRORE + %d",__LINE__);
}

/*
name : return_first
description : ritorna il primo valore del queue senza modificare il queue stesso
type : public
parameters = queue q
return = Item - il primo valore
*/
PUBLIC Item return_first(queue q)
{
    return q->top->data;
}

/*
name : return_last
description : ritorna l'ultimo valore del queue senza modificare lo stesso
type : public
parameters = queue q
return = Item - l'ultimo valore sulla cosa
*/
PUBLIC Item return_last(queue q)
{
    queue new_queue;
    struct node *prev;

    for(prev = NULL,new_queue = q;
     new_queue->top != NULL;
     prev = new_queue->top, new_queue->top = new_queue->top->next)
     ;

     return prev->data;
}

/*
name : create
description : aloca memoria per il queue
type : public
parameters = none (void)
return = queue
*/
PUBLIC queue create(void)
{
    queue s = malloc(sizeof(queue));
    if(s == NULL)
        printf("ERRORE + %d",__LINE__);
    s->top = NULL;
    return s;
}

/*
name : is_empty
description : controla se il queue è vuoto
type : public
parameters = queue q
return = Item - il primo valore
*/
PUBLIC bool is_empty(queue q)
{
    return q->top == 0;
}

/*
name : destroy
description : disctrugge il queue
type : public
parameters = queue (q)
return = none (void)
*/
PUBLIC void destroy(queue s)
{
    make_empty(s);
    free(s);    
}

/*
name : MAKE_EMPTY
description : svutoa il queue
type : private
parameters = queue (s)
return = none (void)
*/
PRIVATE void make_empty(queue s)
{
    while(!is_empty(s))
        pop(s);
}
