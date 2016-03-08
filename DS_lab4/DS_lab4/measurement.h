#ifndef _MEASURMENT
#define _MEASURMENT
 typedef struct
{
	int size;
	double *measu;
}Tmeasurement;

Tmeasurement readMeasurements(char *filename);
void printMeasurements(Tmeasurement m);
double meanMeasurements(Tmeasurement m);
void incMeasurements(Tmeasurement m, double increment);
void copy_meas(Tmeasurement *meas1,Tmeasurement *meas2);
#endif