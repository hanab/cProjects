#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#define LENGTH 25 /* maximum length of string */

#define NUMBER_OF_ITEMS 100 /* maximum number of items the sales man can store */


typedef struct item_decription
{
char name_of_item[LENGTH]; 
float price;
int numsale;  
int numsold;

} description;


#endif