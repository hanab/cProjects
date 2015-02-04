#include <stdio.h>
#include <string.h>
#include "data.h"

/* returns zero on success */
int readString(char *str, int maxsize)
{
	int len = 0;
	if(fgets(str, maxsize, stdin) == NULL) {
		return -1;
	}
	len = strlen(str);
	if(str[len - 1] == '\n') str[len - 1] = '\0';

	return 0;
}


/* returns zero on success */

int readInt(int *value)
{
	char tmp[40];

	if(fgets(tmp, 40, stdin) == NULL) {
		return -1;
	}
	if(sscanf(tmp, "%d", value) != 1) {
		return -2;
	}

	return 0;
}

int readfloat(float *amount)
{
	char tmp[40];

	if(fgets(tmp, 40, stdin) == NULL) {
		return -1;
	}
	if(sscanf(tmp, "%f", amount) != 1) {
		return -2;
	}

	return 0;
}

int readEntry(description *entry)
{
	int error = 0;
	printf("Enter name of the item: ");
	if(readString(entry->name_of_item, LENGTH)) error++;

	printf("Enter number of items avelable for sale : ");
	if(readInt(&(entry->numsale))) error++;

	printf("Enter number of items sold: ");
	if(readInt(&(entry->numsold))) error++;

	printf("Enter price of item: ");
	if(readfloat(&(entry->price))) error++;
     return error;
}
