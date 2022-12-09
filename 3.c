#include <math.h>
#include "radio.h"

double precision_analysis( double *radioactivity, double *time, int N )
{
	int i = 0, M = 10;
	double d_exp = 0, d_linear = 0;

	while (M <= N)
	{
		/*for (i = 0; i < M; i++)															
		{   
			decay_rate += (time[i] / (1 - radioactivity[i])) / M;						
			decay_time += -1 * (time[i] / log(radioactivity[i])) / M; 					
		}*/
		double decay_time = nonlinear_equation(radioactivity, time, M, PRECISION);
		double decay_rate = linear_equation(radioactivity, time, M);

		printf("decay_time = %lf decay_rate = %lf M = %d ", decay_time, decay_rate, M);

		d_exp = dev_exp(radioactivity, time, M, decay_time);							
		d_linear = dev_linear(radioactivity, time, M, decay_rate); 					

		printf("d_exp = %lf d_linear = %lf \n", d_exp, d_linear);

		if (d_linear > 2 * d_exp)														
			break;

		M++;
	}

	return fabs(time[0] - time[M - 1]);														
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