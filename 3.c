#include <math.h>
#include "kirpich.h"

double precision_analysis( double *radioactivity, double *time, int N )
{
	int i = 0, M = 10, d_exp = 0, d_linear = 0;

	while (M <= N)
	{
		/*for (i = 0; i < M; i++)															
		{   
			decay_rate += (time[i] / (1 - radioactivity[i])) / M;						
			decay_time += -1 * (time[i] / log(radioactivity[i])) / M; 					
		}*/

		d_exp = dev_exp(radioactivity, time, M, nonlinear_equation(radioactivity, time, M, 0.0001));							
		d_linear = dev_linear(radioactivity, time, M, linear_equation(radioactivity, time, M)); 					

		if (d_exp > 2 * d_lin)														
			break;

		M++;
	}

	return time[0] - time[M - 1];														
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