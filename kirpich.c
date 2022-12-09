#include <math.h>
#include "kirpich.h"

double precision_analysis( double *radioactivity, double *time, int N )
{
	int i = 0, M = 10, dev_exp = 0, dev_linear = 0;

	while (M <= N)
	{
		double decay_rate = 0, decay_time = 0;

		for (i = 0; i < M; i++)															// найти decay_rate и decay_time
		{
			decay_rate += (time[i] / (1 - radioactivity[i])) / M;						// посчитал среднее арифметическое decay_rate
			decay_time += -1 * (time[i] / log(radioactivity[i])) / M; 					// посчитал среднее арифметическое decay_time
		}

		dev_exp = dev_exp(radioactivity, time, M, decay_time);							// посчитал среднеквадратичное отклонение экспоненциальной интерполяции на М точках
		dev_linear = dev_linear(radioactivity, time, M, decay_rate); 					// посчитал среднеквадратичное отклонение линейной интерполяции на М точках

		if (dev_exp > 2 * dev_lin)
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