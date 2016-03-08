
#ifndef _TIME
#define _TIME
typedef struct { // datatype time
 int hour;
 int minute;
} Ttime;

void read_Ttime(Ttime *p, char *prompt);
void print_Ttime(Ttime t) ;
Ttime time_diff(Ttime t1, Ttime t2);
int compare_Ttime(Ttime time1, Ttime time2);
void print_string(char s[] );
#endif