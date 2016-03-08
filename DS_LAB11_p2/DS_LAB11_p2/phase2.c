#include"phase2.h"
#include <stdio.h>
#include <stdlib.h>
Titemtype *CreateType(void(*print)(void *p),
	int(*cmp)(void *p1, void *p2),
	void(*copy)(void *to, void *from),
	void(*del)(void *p)){
	Titemtype *p;
	p = malloc(sizeof(Titemtype));
	p->cmp = cmp;
	p->copy = copy;
	p->del = del;
	p->print = print;
	return p;

}
void DestroyType(Titemtype *p)
{
	free(p);
}
Titem CreateItem(void *data, Titemtype *type)
{
	Titem item;
	item.data = data;
	item.type = type;
	return item;
}
void DestroyItem(Titem item)
{
	item.type->del(item.data);


}
void PrintItem(Titem item)
{
	item.type->print(item.data);

}
int CmpItem(Titem item1, Titem item2)
{
	return(item1.type->cmp(item1.data, item2.data));

}