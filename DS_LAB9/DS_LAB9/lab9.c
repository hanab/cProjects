/* dynlist4a.c -- Dynamic linked linear list
*
* The abstraction is ok, because first and last are are
* incapsulated inside datatype Tlist and all paramaters of
* operation functions are of this type.
*/

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
//void cleanup_list(Tlist *list);

// Application
int main(void)  {
	Tlist list;

	initialize_list(&list);
	insert_to_list_end(&list, 'a');
	insert_to_list_end(&list, 'b');
	insert_to_list_end(&list, 'c');
	insert_to_list_end(&list, 'd');

	print_list(list);
	//cleanup_list(&list);

	fflush(stdin); getchar();
}


// Implementation of list (only obj is need in appl)
void initialize_list(Tlist *list) {
	*list = NULL;
	}

/*void cleanup_list(Tlist *list) {
	Tpointer aux1, aux2;

	aux1 = list->first;
	while (aux1 != NULL) {
		aux2 = aux1->next;
		free(aux1);
		printf("\nDeleted"); //for testing purposes
		aux1 = aux2;
	}
	initialize_list(list);
}*/

void insert_to_list_end(Tlist *list, Titem data) {
	Tpointer newnode,last;
	
	newnode = (Tpointer)malloc(sizeof(Tnode));
	last= (Tpointer)malloc(sizeof(Tnode));
	newnode->item = data;
	//last=*list;
	if (*list == NULL)
	{
		*list = newnode;
		//last = newnode;
	}//first node
	else
	{    while(last->next!=NULL)
	{last->next = newnode;}
		} //not first node
	  last= newnode;
	  last->next = NULL;
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