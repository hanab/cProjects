# include <time.h>
# include <stdio.h>
int main(int argc, char *argv[]) {
	Ttime  runTime[10];
	int nOfr;
	int i=0;
	Ttime smallest;
	print_string("How many times you have?");
	scanf_s("%d",&nOfr);
	for(i=0;i<nOfr;i++)
	{
	// char buff[80];
	// sprintf(buff, "Give the time %d (hh mm)?", i+1);

	read_time(&runTime[i]," Give the time %d (hh mm)?");

	}
	smallest=runTime[0];
	for(i=1;i<nOfr;i++)
	{
		if(compare_times(runTime[i],smallest)==1)
		{
		smallest=runTime[i];
		}
}
	print_string("Result list:\n");
	for(i=0;i<nOfr;i++)
	{
	print_time(runTime[i]);
	print_time(time_diff(smallest,runTime[i]));
	print_string("\n");
	
	
	}
	
  }


