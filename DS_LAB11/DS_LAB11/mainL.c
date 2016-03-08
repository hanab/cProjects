#define _CRT_SECURE_NO_WARNINGS 
#pragma once

#include"gList.h"
#include <stdio.h>
#include <stdlib.h>

Titemtype *tChar;
/* character */
void DestroyChar(void *p) {
	free(p);
}
void PrintChar(void *p) {
	printf("%c ", *(char *)p);
}
int cmpchar(void *p1, void *p2) {
	if (*(char *)p1 > *(char *)p2)
		return 1;
	else if (*(char *)p1 < *(char *)p2)
		return -1;
	else
		return 0;
}
void copychar(void *to, void *from) {
	*(char *)to = *(char *)from;
}
Titem CreateCharItem(char c) {
	void *p;
	p = malloc(sizeof(char));
	*(char *)p = c;
	return (CreateItem(p, tChar));
}
Titem ReadCharItem(void) {
	char to_be_searched;
	fflush(stdin); scanf("%c", &to_be_searched);
	return (CreateCharItem(to_be_searched));
}
int main() {
	Titem item1, item2;
	tChar = CreateType(PrintChar, cmpchar, copychar, DestroyChar);
	item1 = CreateCharItem('a');
	printf("Given an character item ");
	item2 = ReadCharItem();
	printf("Item1 is "); PrintItem(item1); printf("\n");
	printf("Item2 is "); PrintItem(item2); printf("\n");
	if (!CmpItem(item1, item2))
		printf("Items are the same\n");
	else
		printf("Items are different\n");
	DestroyItem(item1); DestroyItem(item2);
	DestroyType(tChar);
	fflush(stdin); getchar();
}