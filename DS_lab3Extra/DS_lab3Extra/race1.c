#define _CRT_SECURE_NO_WARNINGS 
#pragma once


# include"runner.h"
#include"time.h"
# include <stdio.h>
# define MAX 10
int main(int argc, char *argv[]) {
	Trunner r[MAX];
	int n,i=0;
	Trunner winner;
	printf("How many names you have? ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{ char pro[80];
	sprintf(pro,"Enter the name of runner %d ",i+1);
	fflush(stdin);
	readName(&r[i],pro);
	}
	for (i=0;i<n;i++)
	{
	char pro1[80];
	sprintf(pro1,"Enter the time of runner %d ",i+1);
	fflush(stdin);
	readTime(&r[i],pro1);
	
	}
	winner =r[0];

	for(i=0;i<n;i++)
	{
	if(betterRunner(&r[i],&winner)==1)
	
	winner =r[i];
	
	}
	printf("The winner is :   ");
	displayRunner(&winner);
	printf("\n");
	printf("Result list : \n");
	for (i=0;i<n;i++)
	{   printf("%d. ",i+1);
		displayRunner(&r[i]);
		Print_timdiff(&winner,&r[i]);
		printf("\n");
	
	
	}

  }
