
#ifndef _CHAR
#define _CHAR
#include"phas3.h"
void DestroyChar(void *p);
void PrintChar(void *p);
int cmpchar(void *p1, void *p2);
void copychar(void *to, void *from);
Titem CreateCharItem(char c);
Titem ReadCharItem(void);
#endif