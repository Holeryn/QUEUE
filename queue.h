/*########### DICHIRAZIONI PER IL PREPROCESSORE ###########*/
#ifndef QUEUE
#define QUEUE

#define PUBLIC 
#define PRIVATE static

#define TRUE    1
#define FALSE   0

/*########### DICHIRAZIONI DI TIPO ###########*/
typedef int bool;
typedef int Item;

typedef struct queue_type *queue;

/*
name : create
description : aloca memoria per il queue
type : public
parameters = none (void)
return = queue
*/
PUBLIC queue create(void);

/*
name : push
description : inserisce un valore (n) nel queue
type : public
parameters = queue (q), Item (n) - il valore da inserire 
return = queue
*/
PUBLIC void push(queue q, Item n);

/*
name : pop
description : rimuove un valore dalla coda
type : public
parameters = queue (n)
return = none (void)
*/
PUBLIC void pop(queue n);

/*
name : destroy
description : disctrugge il queue
type : public
parameters = queue (q)
return = none (void)
*/
PUBLIC void destroy(queue q);

/*
name : return_first
description : ritorna il primo valore del queue senza modificare il queue stesso
type : public
parameters = queue q
return = Item - il primo valore
*/
PUBLIC Item return_first(queue q);

/*
name : return_last
description : ritorna l'ultimo valore del queue senza modificare lo stesso
type : public
parameters = queue q
return = Item - l'ultimo valore sulla cosa
*/
PUBLIC Item return_last(queue q);


/*
name : is_empty
description : controla se il queue è vuoto
type : public
parameters = queue q
return = Item - il primo valore
*/
PUBLIC bool is_empty(queue q);

#endif
