#include "time.h"
#include <stdio.h> 


void read_Ttime(Ttime *t, char *prompt) {
      int h, m;

      printf("\n%s : ", prompt);

     do{
		 scanf("%d %d", &h,&m);
	 if(h>23 || h<0 || m>59 ||m<0)
		 printf("wrong input enter again please\n");
	  }
	 while(h>23 || h<0 || m>59 ||m<0);
    
       ( * t).hour= h;
         t->minute = m;
 }

 void print_Ttime(Ttime t) {
       printf("%.2d:%.2d    ", t.hour,t.minute);
  }

 int compare_Ttime(Ttime time1, Ttime time2) {

	int time1_m,time2_m;
	time1_m=(time1.hour)*60+time1.minute;
	time2_m=(time2.hour)*60+time2.minute;

	if(time1_m >time2_m) {
		return 1;
	}

	else if(time1_m == time2_m) {
	return 0;
	}

	else {
	return -1;
	}


 }
 Ttime time_diff(Ttime t1, Ttime t2) {
      int diff;
	  Ttime durat;

     diff = (t2.hour*60+t2.minute)-(t1.hour*60+t1.minute);
     durat.hour=diff/60;
     durat.minute=diff%60;
	 return durat;

 }
 void print_string(char s[] )
 {
 printf(s);
 
 }