# include "time.h"
#ifndef _TRUNNER
#define _TRUNNER
typedef struct { // datatype time
 Ttime time;
 char name[50];
} Trunner;
void readName(Trunner *runner, const char *prompt);
void readTime(Trunner *runner, const char *prompt);
void displayRunner(const Trunner *runner);
int betterRunner(const Trunner *runner1, const Trunner *runner2);
void Print_timdiff(const Trunner *r1,const Trunner *r2);
#endif