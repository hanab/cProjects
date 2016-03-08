# include<stdio.h>
# include "list.h"
# include "time_list.h"
DO_LIST_IMP(Ttime,10) 
	int read_item_Ttime(Ttime *c)
{
	read_Ttime(c,"Enter time");

}
void print_item_Ttime(Ttime c)

{

	print_Ttime(c);
}
int compare_item_Ttime(Ttime c1 ,Ttime c2)
{

	compare_Ttime(c1,c2);
}


