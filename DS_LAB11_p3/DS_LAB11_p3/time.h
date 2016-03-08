#ifndef _TIME
#define _TIME
#include"phas3.h"
typedef struct { // datatype time
	int hour;
	int minute;
} Ttime;
void DestroyTime(void *p);
void CopyTime(void *to, void *from);
void PrintTime(void *t);
int CmpTime(void *time1, void *time2);
Titem CreateTimeItem(int h,int m);
Titem ReadTimeItem(void);
#endif