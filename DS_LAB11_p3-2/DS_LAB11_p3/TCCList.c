#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include"phas3.h"
#include"char.h"
#include"time.h"
#include"complex.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct node *Tpointer;
typedef struct node {
	Titem item;
	Tpointer next;
} Tnode;
typedef Tpointer Tlist;
Titemtype *tChar,*tComplex,*tTime;
void initialize_list(Tlist *list);
void insert_to_list_end(Tlist *list, Titem data);
void print_list(Tlist list);
void cleanup_list(Tlist *list);
void delete_first(Tlist *list);
void delete_last(Tlist *list);
int find_pos_in_list(const Tlist *list, Titem item, int *pos);
void cleanup_list(Tlist *list);
void initialize_list(Tlist *list) {
	*list = NULL;
}

void cleanup_list(Tlist *list) {
	Tpointer aux1, aux2;

	aux1 = *list;
	while (aux1 != NULL) {
		aux2 = aux1->next;
		DestroyItem(aux1->item);
		free(aux1);
		printf("\nDeleted"); //for testing purposes
		aux1 = aux2;
	}
	initialize_list(list);
}

void insert_to_list_end(Tlist *list, Titem data) {
	Tpointer newnode;
	Tpointer last = *list;
	newnode = (Tpointer)malloc(sizeof(Tnode));
	newnode->item = data;
	newnode->next = NULL;

	if (*list == NULL)
	{
		*list = newnode;

		//last = newnode;
	}//first node
	else
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		//not first node
		last->next = newnode;
	}
}

void print_list(Tlist list) {
	Tpointer what;

	printf("\nList 4 :");
	what = list;
	while (what != NULL) {
		what->item.type->print(what->item.data);
		what = what->next;
	}
}
void delete_first(Tlist *list)
{
	Tpointer aux;
	if (*list == NULL)
	{
		printf("list empty\n");
	}
	else {
		aux = *list;
		*list = (*list)->next;
		free(aux);
	}
}
void delete_last(Tlist *list)

{
	Tpointer aux1, aux2;
	if (*list == NULL)
	{
		printf("list empty\n");
	}
	else if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
	}

	else
	{
		aux1 = *list;
		while (aux1->next->next != NULL)
		{
			aux1 = aux1->next;

		}
		aux2 = aux1->next;
		aux1->next = NULL;
		free(aux2);
	}

}
int find_pos_in_list(const Tlist *list, Titem item, int *pos)
{

	Tpointer aux = *list;
	int count = 0;
	while (aux != NULL)
	{

		if (aux->item.type->cmp(aux->item.data, item.data) == 0)
		{
			*pos = count + 1;
			return 1;
		}

		count++;
		aux = aux->next;

	}
	return 0;

}
int main() {
	
	Tlist list;
	Titem to_be_searched;
	int order_no;
	initialize_list(&list);
	
	tChar = CreateType(PrintChar, cmpchar, copychar, DestroyChar);
	tComplex = CreateType(PrintComplex, CmpComplex, CopyComplex, DestroyComplex);
	tTime = CreateType(PrintTime, CmpTime, CopyTime, DestroyTime);
	insert_to_list_end(&list, CreateCharItem('x'));
	insert_to_list_end(&list, CreateCharItem('a'));
	insert_to_list_end(&list, CreateCharItem('b'));
	insert_to_list_end(&list, CreateCharItem('c'));
	insert_to_list_end(&list, CreateComplexItem(1, 2));
	insert_to_list_end(&list, CreateCharItem('d'));
	insert_to_list_end(&list, CreateTimeItem(23, 30));
	insert_to_list_end(&list, CreateCharItem('y'));
	print_list(list);
	printf("\nEnter first character to be searced\n");
	to_be_searched = ReadCharItem();
	if (find_pos_in_list(&list, to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");
	DestroyItem(to_be_searched);
	printf("Enter first complex number to be searced\n");
	to_be_searched = ReadComplexItem();
	if (find_pos_in_list(&list, to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");
	DestroyItem(to_be_searched);
	printf("Enter first time to be searced\n");
	to_be_searched = ReadTimeItem();
	if (find_pos_in_list(&list, to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");
	DestroyItem(to_be_searched);
	delete_first(&list);
	print_list(list);
	delete_last(&list);
	print_list(list);
	cleanup_list(&list);
	DestroyType(tChar); DestroyType(tComplex); DestroyType(tTime);
	fflush(stdin); getchar();
}