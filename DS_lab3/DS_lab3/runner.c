#define _CRT_SECURE_NO_WARNINGS 
#pragma once

# include "runner.h"
# include <stdio.h>
# include<string.h>

void readName(Trunner *runner, const char *prompt)
{
	printf("%s\n",prompt);
	fgets(runner->name,50,stdin);
	if((strlen(runner->name)>0)&&runner->name[strlen(runner->name)-1]=='\n')
		runner->name[strlen(runner->name)-1]='\0';

}
void readTime(Trunner *runner, const char *prompt)
{
	char temp[100];
	strcpy(temp,prompt);
	read_time(&runner->time,temp);
}
void displayRunner(const Trunner *runner)
{  
	printf("%s    ",&runner->name);
	print_time(runner->time);

}
int betterRunner(const Trunner *runner1, const Trunner *runner2)
{
	return compare_times(runner1->time,runner2->time);


}
void Print_timdiff(const Trunner *r1,const Trunner *r2)
{
	print_time(time_diff(r1->time,r2->time));

}