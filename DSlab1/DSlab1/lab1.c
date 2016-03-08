/*
* lab1.c 
*
* Written by Hana Demas
*/
#include <stdio.h> 

typedef struct { // datatype time
 int hour;
 int minute;
} Ttime;

void read_time(Ttime *p, char *prompt);
void print_time(Ttime t) ;
void time_diff(Ttime t1, Ttime t2,Ttime *durat);
int compare_times(Ttime time1, Ttime time2);

int main(int argc, char *argv[]) {
	Ttime t1,t2;
	Ttime duration={1,4};
	
    read_time(&t1,"Enter starting time in 24 hours format");
    read_time(&t2,"Enter ending time in 24 hours format");

   if(compare_times(t1,t2)==1) {
  time_diff(t1,t2,&duration);
  printf("Duration of the process is ");
  print_time(duration);
   }
  else { 
	  printf("duration undefiend\n");
  }


}
 void read_time(Ttime *t, char *prompt) {
      int h, m;

      printf("\n%s", prompt);

     do {
        printf("\nEnter hours\n");
	    scanf_s("%d", &h);
     } while(h>23||h<0);

    do {
        printf("\nEnter minuts\n");
		scanf_s("%d", &m);
	} while(m>59||m<0);

    t->hour= h;
    t->minute = m;
 }
 void print_time(Ttime t) {
       printf("%.2d:%.2d \n", t.hour,t.minute);
  }

 int compare_times(Ttime time1, Ttime time2) {

	int time1_m,time2_m;
	time1_m=(time1.hour)*60+time1.minute;
	time2_m=(time2.hour)*60+time2.minute;

	if(time1_m >time2_m) {
		return -1;
	}

	else if(time1_m == time2_m) {
	return 0;
	}

	else {
	return 1;
	}


 }
 void time_diff(Ttime t1, Ttime t2,Ttime *durat) {
      int diff;

     diff = (t2.hour*60+t2.minute)-(t1.hour*60+t1.minute);
     durat->hour=diff/60;
     durat->minute=diff%60;

 }