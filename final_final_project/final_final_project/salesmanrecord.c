#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <time.h>

#include "data.h"
#include "readers.h"
#define SALESMAN_RECORDS "record.dat"

void printMenu(void);
void initialize(description * entries);
int writeEntries(description *entries);
int readrecords(description *entries);
void printRecords(FILE * file, description entries);
void additem(description *entries, int *);
void saleitem(description *entries,int size);
int printreport(description*entries,int itemcount );

int main(int argc, char *argv[])
{
	description items[NUMBER_OF_ITEMS]={""}; 
	int selection = -1;
	int itemnumbers=0;

	do {
		printMenu();
		/* loop until user enters a number */
		while(readInt(&selection)) {
			printf("Invalid selection\n");
			printMenu();
		}/* check which option was selected */
		switch (selection)
		{
		case 1:
			initialize(items);
			break;
		case 2:
		    
			if(writeEntries(items)!=0)
			printf("Error! Cannot save to file!\n");
			break;
		case 3:
			itemnumbers=readrecords(items);
			break;
		case 4:
			additem(items, &itemnumbers);
			break;
		case 5:saleitem(items,itemnumbers);
			break;
	    case 6:if(printreport(items,itemnumbers )==0)
				  printf("No item found\n");
			 break;
		default:printf("Invalid selection\n");
			break;
		}
		
	} while(selection);

	return 0;
}


void printMenu(void)
{
	printf("Select action (0-6)\n");
	printf("1 - initialize stock listing\n");
	printf("2 - save stock listing to disk \n");
	printf("3 -read stock listing from disk \n");
	printf("4 -add a new item to list \n");
	printf("5 - decrease items for sale & increase number of sold items or replenish item\n");
	printf("6 - print a report \n");
	printf("0 - Exit program\n");
}	
void initialize(description *entries) {
	entries[0].name_of_item[0] = '\0'; // set the name of the first element to null, which would be considered the terminating element in the array

	printf("Successfully cleared all items.\n");

	system("pause");
}
void printRecords(FILE * file, description entries) {
	

	fprintf(file, "name of item: %s\n", entries.name_of_item);
	fprintf(file, "number of item avaliable for sale: %d\n",entries.numsale );
	fprintf(file, "number of items sold: %d\n", entries.numsold);
	fprintf(file, "price of item: %.4f\n", entries.price);
	
}


void additem(description *entries, int *num)
{   
	
	int i;
	
     
    /* for (i = 0; i <  (NUMBER_OF_ITEMS-1)  && entries[i].name_of_item != '\0'; i++)
	{
		// execute loop until we find the position of the terminating element
	}
	
	 int pos = 0;
	 i = 0;
	 while(pos < NUMBER_OF_ITEMS)
	 {
		 if(entries[i].name_of_item != '\0')
			 i = pos;
		 pos ++;
	 }*/
	i = *num;
  
		do{
			readEntry(entries);
			if(entries->numsale<0||entries->numsold<0||entries->price<0)
				printf("incorrect input,Enter description again.\n");
		}
		while(entries->numsale<0||entries->numsold<0||entries->price<0);
	printf("\n This record added successfully( %d).\n", i+1);
	entries[i]=*entries;
	printRecords(stdout, entries[i]);  
	*num = *num +1;
	
       system("pause");
	
	
}

 int readrecords(description *entries)
  {FILE * infile;
	int i;
	infile=fopen(SALESMAN_RECORDS,"rb");

	if (infile == NULL)
	{
		printf("Unable to open file %s for reading.\n",SALESMAN_RECORDS );
		return 0;
	}

	for (i = 0; i <NUMBER_OF_ITEMS  && !feof(infile); i++) // execute while end of file is not reached and while there is still space in memory
	{
		if (fread(&entries[i], sizeof(description), 1, infile) != 1) // if item could not be read successfully
		{
			break; // mark current element as invalid, it will become terminating element after a few lines
		}
	}

	printf("\n");

	if (i == 0)
	{
		printf("There were no items to read.\n");
	}
	else
	{
		printf("Successfully read %d items from disk.\n", i);

		if (i != NUMBER_OF_ITEMS ) // if i is not the maximum possible
		{
			entries[i].name_of_item[0] = '\0'; // set the current element as terminating
		}
	}

	fclose(infile);
	system("pause");
	return i;
	
}
    /* returns zero if entries were written to file and non-zero if error occurred */
int writeEntries(description *entries)
{
	FILE * outfile;
	int i;
	outfile = fopen(SALESMAN_RECORDS, "wb");
	if (outfile == NULL)
	{
		printf("Unable to open file %s for writing.\n", SALESMAN_RECORDS);
		return -1;
	}

	for (i = 0; i < NUMBER_OF_ITEMS && entries[i].name_of_item[0] != '\0'; i++)
	{
		if (fwrite(&entries[i], sizeof(description), 1, outfile) != 1)
		{
			printf("Error writing record to disk.\n");
			fclose(outfile);
			system("pause");
			return 1;
			
		}
	}

	if (i == 0)
	{
		printf("There were no items to save.\n");
	}
	else
	{
		printf("Successfully saved %d items to disk.\n", i);
	}

	fclose(outfile);

	system("pause");
	return 0;
}
 void saleitem(description *entries,int size)
 {
 int i, choice, change,selection;
	

	printf("Choose the item you want to modify (enter an integer):\n");
	for (i = 0; i < size; ++i) {
		printf("%i\n", i + 1);
		printRecords(stdout, entries[i]);
	}
	readInt(&choice);
	if (choice < 1 || choice > size) {
		printf("Index out of range!\n");
		return;
	}
	printf("You've chosen the following item:\n");
	printRecords(stdout, entries[choice - 1]);
	printf("Enter 1 to increase sold item and 2 to increase items for sale\n");
	readInt(&selection);

	switch(selection)
	{case 1:
		
		do
		{ 
			printf("Enter how many items of this type sold\n");
			readInt(&change);
		   if(change>entries[choice-1].numsale)
		   printf("The maximum avelable items are %d.Enter a valid number\n",entries[choice-1].numsale);
		    }
		while(change>entries[choice-1].numsale);
       entries[choice-1].numsale-=change;
	    entries[choice-1].numsold+=change;
	               break;
   case 2:
	   printf("Enter how many items of this type you want to add\n");
	  readInt(&change);
        entries[choice-1].numsale+=change;
		break;
	
	default : printf("Wrong input enter 1 or 2");
		  break;
	}
	system("pause");
 }
 int printreport(description*entries,int itemcount )
 {   
	 int i, count = 0;
	 float totalrevenue=0.0;
 
 for (i = 0; i < itemcount; ++i)
		
			{
				printRecords(stdout, entries[i]);
				totalrevenue+=((entries[i].price)*(entries[i].numsold));
			   ++count;
               }
 
   printf("The total revenue is %.5f\n",totalrevenue);

	
   return count;
 
 
 }