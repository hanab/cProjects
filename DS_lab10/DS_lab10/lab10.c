
/* dynlist4a.c -- Dynamic linked linear list
*
* The abstraction is ok, because first and last are are
* incapsulated inside datatype Tlist and all paramaters of
* operation functions are of this type.
*/
#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char Titem;

// Interface of list
typedef struct node *Tpointer;
typedef struct node {
	Titem item;
	Tpointer next;
} Tnode;
typedef Tpointer Tlist;
void initialize_list(Tlist *list);
void insert_to_list_end(Tlist *list, Titem data);
void print_list(Tlist list);
void cleanup_list(Tlist *list);
void delete_first(Tlist *list);
void delete_last(Tlist *list);
int find_pos_in_list(const Tlist *list, Titem item, int *pos);
void cleanup_list(Tlist *list);
Tlist revList(Tlist *list);

// Application
int main(void)  {
	Tlist list,list2;
	int order_no;
	char to_be_searched;
	initialize_list(&list);
	delete_last(&list);
	insert_to_list_end(&list, '?');
	delete_last(&list);
	insert_to_list_end(&list, 'x');
	insert_to_list_end(&list, 'a');
	insert_to_list_end(&list, 'b');
	insert_to_list_end(&list, 'c');
	insert_to_list_end(&list, 'd');
	insert_to_list_end(&list, 'y');
	//delete_first(&list);
	print_list(list);
	list2=revList(list);
	print_list(list2);
	printf("Enter first character to be searced\n");
	fflush(stdin); scanf("%c", &to_be_searched);
	if (find_pos_in_list(&list2,to_be_searched, &order_no))
	printf("The order no is %d\n", order_no);
	else
	printf("Not found\n");
	printf("Enter second character to be searced\n");
	fflush(stdin); scanf("%c", &to_be_searched);
	if (find_pos_in_list(&list2, to_be_searched, &order_no))
	printf("The order no is %d\n", order_no);
	else
	printf("Not found\n");
	
	delete_first(&list2);
	print_list(list2);
	delete_last(&list2);
	print_list(list2);
	fflush(stdin); getchar();
}


// Implementation of list (only obj is need in appl)
void initialize_list(Tlist *list) {
	*list = NULL;
}

void cleanup_list(Tlist *list) {
	Tpointer aux1, aux2;

	aux1 = *list;
	while (aux1 != NULL) {
		aux2 = aux1->next;
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
		printf("%c ", what->item);
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

	Tpointer aux=*list;
	int count=0;
	while(aux!=NULL)
	{
	
	if(aux->item==item)
	{
	*pos=count+1;
	return 1;
	}
	
	count++;
	aux=aux->next;
	
	}
	return 0;

}
Tlist revList(Tlist list)
{  Tlist rev;
 Tpointer what;
 rev=NULL;

 while(list!=NULL)
 {
	 what=list->next;
	 list->next=rev;
	 rev=list;
	 list=what;

 
 }

 return rev;
}