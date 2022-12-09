#include <math.h>
#include "kirpich.h"

double precision_analysis( double *radioactivity, double *time, int N )
{
	
}

double dev_exp( double *radioactivity, double *time, int M, double decay_time ) 
{
	double sum = 0;
	int i = 0;

	for (i = 0; i < M; i++) 
	{
		sum += pow((radioactivity[i] - exp(-time[i] / decay_time)), 2);
	}

	return sqrt(sum) / M;
}

double dev_linear( double *radioactivity, double *time, int M, double decay_rate ) 
{
	double sum = 0;
	int i = 0;

	for (i = 0; i < M; i++) 
	{
		sum += pow((radioactivity[i] - 1 + time[i] / decay_rate), 2);
	}

	return sqrt(sum) / M;
}