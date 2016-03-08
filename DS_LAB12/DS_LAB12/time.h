#ifndef _TIME
#define _TIME
typedef struct { // datatype time
	int hour;
	int minute;
} Ttime;

void read_time(Ttime *p, char *prompt);
void print_time(Ttime t);
Ttime time_diff(Ttime t1, Ttime t2);
int compare_times(const void* time1, const void* time2);
int compare_minute(const void* time1, const void* time2);
void print_string(char s[]);
#endif