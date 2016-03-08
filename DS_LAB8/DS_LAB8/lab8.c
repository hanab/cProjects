
#include"lab8.h"
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include<stdlib.h>

/* The interface of queue */
#define INC 3

Tqueue CreateQueue(Tboolean fCircular){
	Tqueue Pqueue;
	//Pqueue = NULL;
	Pqueue = (Tqueue)malloc( sizeof(_Tqueue));
	Pqueue->size =INC;
	Pqueue->array = (Titem*)malloc(Pqueue->size * sizeof(Titem));
	Pqueue->number_of_items = 0;
	Pqueue->first = 0;
	Pqueue->last = -1;
	Pqueue->f=fCircular;             
	return Pqueue;

}
Tboolean enqueue(Tqueue  Pqueue, Titem item){
	Titem *q1;
	
	int i, j, n;
	j = Pqueue->first;
	if (Pqueue->f)
	{
		j = Pqueue->first;
		if (Pqueue->number_of_items >= Pqueue->size)
		{
			Pqueue->size += INC;

			q1 = (Titem*)malloc((Pqueue->size)*sizeof(Titem));
			for (n = 1, i = Pqueue->first; n <= Pqueue->number_of_items; n++)
			{
				q1[i] = Pqueue->array[j++];
				i++;
			}
			free(Pqueue->array);
			Pqueue->array = q1;
			Pqueue->last++;
			if (Pqueue->last > Pqueue->size - 1)
				Pqueue->last = 0;
			Pqueue->array[Pqueue->last] = item;
			Pqueue->number_of_items++;
			return (OK);

		}
		else {
			Pqueue->last++;
			if (Pqueue->last > Pqueue->size - 1)
				Pqueue->last = 0;
			Pqueue->array[Pqueue->last] = item;
			Pqueue->number_of_items++;
			return (OK);
		}


	}

	if (Pqueue->number_of_items >= Pqueue->size)
	{
		Pqueue->size += INC;

		q1 = (Titem*)malloc((Pqueue->size)*sizeof(Titem));
		for (i = 0; i < Pqueue->number_of_items; i++)
		{
			q1[i] = Pqueue->array[j++];
		}
		free(Pqueue->array);
		Pqueue->array = q1;
		Pqueue->last = Pqueue->number_of_items;
		Pqueue->array[Pqueue->number_of_items++] = item;
		
		//printf("size is increased and now %d item\n", Pqueue->number_of_items);
	}

	else {
		Pqueue->last = Pqueue->number_of_items;
		Pqueue->array[Pqueue->number_of_items++] = item;
		

	}
	return (OK);

}
Tboolean dequeue(Tqueue  Pqueue, Titem *Pitem)
{
	if (Pqueue->f)
	{
		if (Pqueue->number_of_items == 0)
			return(NOT_OK);
		else {
			*Pitem = Pqueue->array[Pqueue->first++];
			if (Pqueue->first > Pqueue->size - 1)
				Pqueue->first = 0;
			Pqueue->number_of_items--;
			return (OK);
		}

	}
	else{


		int i;

		if (Pqueue->number_of_items == 0)
			return(NOT_OK);
		else {

			*Pitem = Pqueue->array[0];
			for (i = 0; i < Pqueue->number_of_items - 1; i++)
				Pqueue->array[i] = Pqueue->array[i + 1];
			Pqueue->number_of_items--;

			return (OK);
		}


	}




}
void print_queue(Tqueue  Pqueue)
{

	int i, n;
	printf("\nQueue now: \n\n");
	for (n = 1, i = Pqueue->first; n <= Pqueue->number_of_items; n++) {
		printf(" %c ", Pqueue->array[i]);
		i++;
		if (i>Pqueue->size - 1)
			i = 0;
	}
	printf("\n\n");

}
void DestroyQueue(Tqueue  Pqueue)
{
	free(Pqueue);
	
}