#include<stdio.h>
#include<stdlib.h>
typedef int Titem;
typedef struct node *Tpointer;
typedef struct node {
	Titem item;
	Tpointer next,
		prev;
} Tnode;
typedef Tpointer Tdbl;
void initialize_dbl(Tdbl *list);
void insert_to_dbl_front(Tdbl *list, Titem item);
void insert_to_dbl_back(Tdbl *list, Titem item);
void print_dbl(Tdbl list);
void print_dbl_reverse(Tdbl list);

void initialize_dbl(Tdbl *list)
{
	*list = NULL;

}
void insert_to_dbl_front(Tdbl *list, Titem item)
{
	Tpointer newnode;
	
	
	newnode = (Tpointer)malloc(sizeof(Tnode));
	newnode->item = item;
	
	if (*list == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*list = newnode;
		
	}
	else
	{
		
		newnode->next = *list;
		newnode->prev = NULL;
		(*list)->prev = newnode;
		*list=newnode;

	}
}
void insert_to_dbl_back(Tdbl *list, Titem item)
{
	Tpointer newnode;
	newnode = (Tpointer)malloc(sizeof(Tnode));
	newnode->item = item;
	
	if (*list == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*list = newnode;

	}
	else
	{
		Tpointer last = *list;
		last= *list;
		while (last->next != NULL)
		{
			last= last->next;
		}
		newnode->prev = last;
		last->next = newnode;
		newnode->next = NULL;


	}


}
void print_dbl_reverse(Tdbl list)
{
	Tpointer what;
	Tpointer rev;
	if (list == NULL)
	{
		printf("List empty\n");
	}
	else
	{
		what = list;
		while (what->next != NULL) {
			
			what = what->next;
		}
		rev = what;
		while (rev != NULL)
		{
			printf("%d ", rev->item);
			rev = rev->prev;
		}

	}
	printf("\n");
}
void print_dbl(Tdbl list)
{

	Tpointer what;
	if (list == NULL)
	{
		printf("List empty\n");
	}
	else
	{
		what = list;
		while (what != NULL) {
			printf("%d ", what->item);
			what = what->next;
		}

	}
	printf("\n");


}
int main(void) {
	Tdbl dbl;
	initialize_dbl(&dbl);
	print_dbl(dbl);
	print_dbl_reverse(dbl);
	insert_to_dbl_back(&dbl, 10);
	print_dbl(dbl);
	print_dbl_reverse(dbl);
	insert_to_dbl_front(&dbl, 20);
	print_dbl(dbl);
	print_dbl_reverse(dbl);
	insert_to_dbl_back(&dbl, 30);
	print_dbl(dbl);
	print_dbl_reverse(dbl);
	insert_to_dbl_front(&dbl, 40);
	print_dbl(dbl);
	print_dbl_reverse(dbl);
	insert_to_dbl_back(&dbl, 50);
	print_dbl(dbl);
	print_dbl_reverse(dbl);
	fflush(stdin); getchar();
}