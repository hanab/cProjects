# include<stdio.h>
# include "ch_list.h"
# include"time_list.h"
int main () {
     TListTchar list; Tchar item;
	 TListTtime list1; Ttime item1;
     int i;
	
 

     initialize_list_Tchar(&list);
     printf("\n Enter items in any order\n");

     for (i = 0 ; i < 5 ; i++) {
        read_item_Tchar(&item);
        if (!insert_item_Tchar(&list, item))
            printf("\nList is full");
     }

     printf("\nList ouputted using for loop and retrieve_ith function:\n");
     for (i=0; i<number_of_items_Tchar(&list); i++) {
		retrieve_ith_Tchar(&list, i, &item);
		print_item_Tchar(item);
     }

	 initialize_list_Ttime(&list1);
     printf("\n Enter items in any order\n");

     for (i = 0 ; i < 5 ; i++) {
        read_item_Ttime(&item1);
        if (!insert_item_Ttime(&list1, item1))
            printf("\nList is full");
     }

     printf("\nList ouputted using for loop and retrieve_ith function:\n");
     for (i=0; i<number_of_items_Ttime(&list1); i++) {
		retrieve_ith_Ttime(&list1, i, &item1);
		print_item_Ttime(item1);
		printf("\n");
     }

	 

     
     return 0;
}