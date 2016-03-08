#include "time.h"
 
int main(int argc, char *argv[]) {
	Ttime t1,t2;
	Ttime duration={1,4};
	
    read_time(&t1,"Enter starting time in 24 hours format");
    read_time(&t2,"Enter ending time in 24 hours format");

   if(compare_times(t1,t2)==1) {
   duration =time_diff(t1,t2);
   print_string("Duration of the process is ");
   print_time(duration);
   }
  else { 
	  print_string("duration undefiend\n");
  }}


