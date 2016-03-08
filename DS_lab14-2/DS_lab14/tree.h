#ifndef _BST
#define _BST

typedef void* Titem;
typedef struct node *Tpointer;
typedef struct node {
	Tpointer left, right;
	Titem item;
} Tnode;
typedef Tpointer TBinSTree;
void initialize_bst(TBinSTree *tree);
void insert_to_tree(TBinSTree *tree, Titem data, int(*f)(Titem, Titem));
int isInTree(TBinSTree tree, Titem data, int(*f)( Titem, Titem), int count);
int maxdepth(TBinSTree tree);
int mindepth(TBinSTree tree);
void print_tree_in_order_traverse(TBinSTree tree);

#endif