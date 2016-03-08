#ifndef _LIST
#define _LIST
	// List header template
#define DO_LIST_HEADER(Titem,MAX) \
typedef struct { \
int count; \
Titem array[MAX]; \
} TList##Titem; \
void initialize_list_##Titem(TList##Titem *list); \
int insert_item_##Titem(TList##Titem *list, Titem item); \
int retrieve_ith_##Titem(const TList##Titem *list, int i, Titem *item); \
int number_of_items_##Titem(const TList##Titem *list); \
int list_empty_##Titem(const TList##Titem *list);\
int read_item_##Titem(Titem *c);\
void print_item_##Titem(Titem c);\
int compare_item_##Titem(Titem c1 ,Titem c2);\

// END DO_LIST_HEADER
// List implementation template
#define DO_LIST_IMP(Titem,MAX) \
/* Operation function implementations for ADT list */ \
void initialize_list_##Titem(TList##Titem *list) { \
list->count = 0;\
}\
int insert_item_##Titem(TList##Titem *list, Titem item) {\
	int find_position_##Titem(Titem *array, Titem item, int number_of_items);\
   int make_room_##Titem(Titem *array, int where, int size_of_array);\
	int i;\
     if(list->count < MAX ) {\
	 i = find_position_##Titem(list->array, item,  list->count);\
	 make_room_##Titem(list->array,i, list->count);\
		list->array[i] = item;\
		list->count++;\
		return 1;\
    } else\
		return 0;\
}\
	int retrieve_ith_##Titem(const TList##Titem *list, int i, Titem *item) {\
 if (!(list_empty_##Titem(list)) && i <list->count) {\
		*item = list->array[i];\
		return 1;\
    } else\
		return 0;\
}\
int number_of_items_##Titem(const TList##Titem *list){\
    return list->count;\
}\
int list_empty_##Titem(const TList##Titem *list) {\
    return !list->count;\
}\
int find_position_##Titem(Titem *array, Titem item, int number_of_items) {\
    int i=0;\
	while (compare_##Titem(array[i], item) == -1 && i < number_of_items) i++;\
   return i;\
}\
  int make_room_##Titem(Titem *array, int where, int number_of_items) {\
    int i;\
    if (number_of_items < MAX) {\
	for (i = number_of_items - 1 ; i >= where ; i-- )\
	    array[i+1] = array[i];\
	    return 1;\
	} else\
	    return 0;}




/*
 * These are operation functions for abstract datatype Titem 
 */
 #endif