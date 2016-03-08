# include"runner.h"
# include <stdio.h>
int main(int argc, char *argv[]) {
	Trunner r1,r2;
	readName(&r1,"Enter the name of runner 1");
	readName(&r2,"Enter the name of runner 2");
	readTime(&r1,"Enter the time of runner 1");
	readTime(&r2,"Enter the time of runner 2");

	if(betterRunner(&r1,&r2)==-1)
	{
		print_string("The winner is : ");
	    displayRunner(&r2);
		Print_timdiff(&r2,&r1);
	}
	else if(betterRunner(&r1,&r2)==1)
		{
    printf("The winner is :\n ");
	displayRunner(&r1);
	Print_timdiff(&r1,&r2);

	}
	else
		printf("The race is a tie");


  }
