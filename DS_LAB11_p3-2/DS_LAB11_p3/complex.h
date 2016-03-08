#ifndef _COMPLEX
#define _COMPLEX
#include"phas3.h"
#include<math.h>
 void DestroyComplex(void *p);
 void CopyComplex(void *to, void *from);
 void PrintComplex(void *c);
int CmpComplex(void *c1, void *c2);
Titem CreateComplexItem(double x,double y);
Titem ReadComplexItem(void);
#endif