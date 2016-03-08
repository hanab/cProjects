#define _CRT_SECURE_NO_WARNINGS 
#pragma once
# include"time.h"
#include <stdio.h>
#include <stdlib.h>
Titemtype *tTime;
void DestroyTime(void *p)
{
	free(p);
}
void PrintTime(void *t)
{

	printf("%.2d:%.2d ",((Ttime *)t)->hour,((Ttime *)t)->minute );

}
int CmpTime(void *time1, void *time2)
{
	Ttime *t1 = (Ttime *)time1;
	Ttime *t2 = (Ttime *)time2;
	int time1_m, time2_m;
	time1_m = (t1->hour) * 60 + t1->minute;
	time2_m = (t2->hour) * 60 + t2->minute;

	if (time1_m >time2_m) {
		return -1;
	}

	else if (time1_m == time2_m) {
		return 0;
	}

	else {
		return 1;
	}

}
void CopyTime(void *to, void *from)
{
	Ttime *t1 = (Ttime *)to;
	Ttime *t2 = (Ttime *)from;
	t1->hour = t2->hour;
	t1->minute = t2->minute;

}
Titem CreateTimeItem(int h,int m)
{
	void *p;
	Ttime *t;
	p = malloc(sizeof(Ttime));
	t = (Ttime *)p;
	t->hour = h;
	t->minute = m;
	return (CreateItem(t, tTime));

}
Titem ReadTimeItem(void)
{
	
	int h, m;

	do{
		scanf("%d %d", &h, &m);
		if (h>23 || h<0 || m>59 || m<0)
			printf("wrong input enter again please\n");
	} while (h>23 || h<0 || m>59 || m<0);
	
	return (CreateTimeItem(h,m));
}