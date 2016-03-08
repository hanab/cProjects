
#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include "tree.h"
#include <time.h>
#include"math.h"
#include <stdio.h> 
#include <stdlib.h> 
#define NUMBERS 10000
#define NUM 5
#define  CON log((float)2)
int compare(Titem x, Titem y)
{
	if (*(int *)x < *(int *)y)

		return -1;
	else if (*(int *)x == *(int *)y)
		return 0;
	else
		return 1;



}
void* CreateInt(int num){
	int *p;
	p = (int*)malloc(sizeof(int));
	*p = num;
	return p;

}
float sum = 0;
int main(void){
	int i;
	int item_to_search;
	int count = 0;
	
	TBinSTree tree;

	srand(time(NULL)); // initializes the pseudorandom number generator

	initialize_bst(&tree);

	for (i = 0; i < NUMBERS; i++){
		int num;
		num = rand() % 10000;
		insert_to_tree(&tree, CreateInt(num), compare);
	}
	//print_tree_in_order_traverse(tree);
	for (i = 0; i < NUM; i++){
		count = 0;
		printf("Input %d item to search: ", i + 1);
		scanf("%d", &item_to_search);
		
			isInTree(tree, CreateInt(item_to_search), compare, count);
			sum += isInTree(tree, CreateInt(item_to_search), compare, count);
		
	}
	printf("Theoretical number of comparisions needed is %.2lf\n",(log((float)NUMBERS))/CON);
	printf("Average number of actual comparisions is %.2f\n", sum / NUM);
	printf("Min depth %d,Max depth %d \n", mindepth(tree), maxdepth(tree));
}
