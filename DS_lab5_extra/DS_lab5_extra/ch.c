#include "ch.h"
#include <stdio.h> 
int read_Tchar(Tchar *c) {
    fflush(stdin);	// flush (emtpy) the input keyboard buffer
    *c= getchar();

    return 1;
}

void print_Tchar(Tchar c) {
    printf("%c\n", c);
}

int compare_Tchar(Tchar c1 , Tchar c2) {
    if ((int)c1 < (int)c2)
		return -1;
    else if ((int)c1 == (int)c2)
		return 0;
    else
		return 1;
}
