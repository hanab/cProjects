#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include"time.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

/*
int c1(const void *p1, const void *p2) {
    return compare_times((Ttime *)p1, (Ttime *)p2);
}
*/

int main(void)
{
	int i;
	Ttime array[MAX];
	char buffer[30];
	for ( i = 0; i < MAX; i++)
	{
		sprintf(buffer, "Enter time %d   ", i + 1);
		read_time(&array[i],buffer);
	}

	qsort(array, MAX, sizeof(Ttime), compare_times);
	printf("sorted time\n");
	for (i = 0; i < MAX; i++)
	{
		print_time(array[i]);
		printf("\n");
	}
	qsort(array, MAX, sizeof(Ttime), compare_minute);
	printf("sorted time by minute field\n");
	for (i = 0; i < MAX; i++)
	{
		print_time(array[i]);
		printf("\n");
	}


}