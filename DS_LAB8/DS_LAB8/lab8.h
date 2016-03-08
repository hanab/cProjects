#ifndef _QUEUE
#define _QUEUE
typedef int Titem;
typedef enum { NOT_OK, OK } Tboolean;
typedef struct {
	Titem *array;
	int   number_of_items;
	int size;
	int first;
	int last;
	Tboolean f;
} *Tqueue,_Tqueue;
Tqueue CreateQueue(Tboolean fCircular);
Tboolean enqueue(Tqueue  Pqueue, Titem item);
Tboolean dequeue(Tqueue  Pqueue, Titem *Pitem);
void print_queue(Tqueue  Pqueue);
void DestroyQueue(Tqueue  Pqueue);
#endif