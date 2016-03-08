#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include"complex.h"
#include <stdio.h>
#include <stdlib.h>

Titemtype *tComplex;
void DestroyComplex(void *p)
{
	free(p);
}
void PrintComplex(void *c)
{
	struct _complex *pt = (struct _complex *)c;
	printf("%.lf+j%.lf ", pt->x,pt->y);

}
int CmpComplex(void *c1, void *c2)
{
	struct _complex  *com1 = (struct _complex *)c1;
	struct _complex *com2 = (struct _complex  *)c2;
	
	if (com1->x >com2->x) {
		return -1;
	}

	else if (com1->x== com2->x && com1->y== com2->y) {
		return 0;
	}

	else {
		return 1;
	}

}
void CopyComplex(void *to, void *from)
{
	struct _complex  *c1 = (struct _complex  *)to;
	struct _complex *c2 = (struct _complex  *)from;
	c1->x = c2->x;
	c1->y = c2->y;

}
Titem CreateComplexItem(double x,double y )
{
	void *p;
	struct _complex *pt;
	p = malloc(sizeof(struct _complex ));
	 pt= (struct _complex *)p;
	pt->x = x;
	pt->y = y;
	return (CreateItem(pt, tComplex));

}
Titem ReadComplexItem(void)
{
	
	int r, im;

	
  scanf("%d %d", &r, &im);
		
	
	return (CreateComplexItem(r,im));
}