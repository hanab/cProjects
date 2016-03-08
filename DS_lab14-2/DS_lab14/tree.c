
#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include"tree.h"
#include"stdio.h"
#include"stdlib.h"
void initialize_bst(TBinSTree *tree)
{

	*tree = NULL;
}
void insert_to_tree(TBinSTree *tree, Titem data, int(*f)(Titem, Titem))
{
	Tpointer newnode;
	newnode= *tree;

	if (newnode == NULL)
	{
		newnode = (Tpointer)malloc(sizeof(Tnode));
		newnode->item = data;
		newnode->left = newnode->right = NULL;
		*tree = newnode;
		
	}
	else
	{
		if (f(data, newnode->item)<0)
		{

			insert_to_tree(&newnode->left, data, f);
		}
		else if (f(data, newnode->item)>=0)
			insert_to_tree(&newnode->right, data, f);
	}

}
int isInTree(TBinSTree btree, Titem item, int(*f)(Titem, Titem), int count)
{
	
	
	if (btree == NULL)
	{
		printf(": not   found  ");
		printf("%d comparision needed\n ", count);
		return count;
	}
	else
	{
		if (f(item, btree->item) == 0)
		{
			printf(":    found ");
			printf("%d comparision needed\n ", count);
			return count;

		}
		else{
			if (f(item, btree->item) == -1)
			{
				count++;
				return isInTree(btree->left, item, f, count);
			}
			
			else if (f(item,btree->item)==1)

			{
				count++;
				return isInTree(btree->right, item, f, count);
			}
			
		}
		
	}


	


}
int maxdepth(TBinSTree tree)
{
	int ld, rd;
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		ld = maxdepth(tree->left);
		rd = maxdepth(tree->right);
		if (ld>rd)
			return (ld + 1);
		else
			return (rd + 1);
	}
}
int mindepth(TBinSTree tree)
{
	int ld, rd;
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		ld = maxdepth(tree->left);
		rd = maxdepth(tree->right);
		if (ld>rd)
			return (rd + 1);
		else
			return (ld + 1);
	}
}
void print_tree_in_order_traverse(TBinSTree tree)
{
	if (tree != NULL)
	{
		
		print_tree_in_order_traverse(tree->left);
		printf(" %d \t", *(int*)tree->item);
		print_tree_in_order_traverse(tree->right);
		
		
	}
}