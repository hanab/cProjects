
#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include "measurement.h"
#include <stdio.h>
# include<stdlib.h>
Tmeasurement readMeasurements(char *filename)
{
	Tmeasurement m={0};
	int i;
	

	FILE *infile=fopen(filename, "r");

	if (infile == NULL)
    {
        fprintf(stderr, "Can't open the file\n");
                exit(1);
    }

	fscanf(infile, "%d",&(m.size));
	 m.measu=(double *)malloc((m.size)*sizeof(double));
	
	 for (i=0;i<m.size;i++)
	 {
	 
	 fscanf(infile, "%lf",&m.measu[i]);
	 
	 
	 }
	 fclose(infile);
    return m;

}
void printMeasurements(Tmeasurement m)
{
	int i;
	printf("The total number of measurment taken is %d: \n",m.size);
	printf("The list of measurments taken: \n");

		for( i=0;i<m.size;i++)
		{printf("%d.%.4f \n ",i+1,m.measu[i]);}
		
}
double meanMeasurements(Tmeasurement m)
{
	double sum=0;
	int i=0;
	for (i=0;i<m.size;i++)
	{
	sum+=m.measu[i];
	}

	return sum/(m.size);

}
void incMeasurements(Tmeasurement m, double increment)
{
	int i;
	for(i=0;i<m.size;i++)
	{
	m.measu[i]+=increment;
	
	}


}
void copy_meas(Tmeasurement *meas1,Tmeasurement* meas2)
{
	int i;
	(*meas2).measu=(double *)malloc((meas1->size)*sizeof(double));
	meas2->size=meas1->size;
	for (i=0;i<meas1->size;i++)
	{
	
	meas2->measu[i]=meas1->measu[i];
	}

	
	 


}