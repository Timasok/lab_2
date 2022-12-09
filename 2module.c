#include <stdio.h>
#include <stdlib.h>

#include "radio.h"

double nonlinear_equation (double *radioactivity, double *time, int N, double precision) // аппроксимация нелинейной функции
{
    double decay_time = 0;
    
    double* decay_arr = (double*) calloc (sizeof(double), N);

    for (int i = 0; i < N; i++)
    {
        decay_arr[i] = -time[i] / log(radioactivity[i]);
    }

    square_sum = 0;
    
    for (int i = 0; i < N; i++)
    {
        square_sum += decay_arr[i]*decay_arr[i];
    }

    decay_time = sqrt(square_sum) / N;

    return decay_time;
}

double model(double *radioactivity, double *time, int N, double point)     // моделирование функции     
{
    for (int i = 0; i < N; i++)
    {
        if (equals(point, time[i])) return radioactivity[i];   
    }
}

double linear_equation (double *radioactivity, double *time, int N) // аппроксимация линейной функции
{
    double decay_rate = 0;
    
    double* decay_arr = (double*) calloc (sizeof(double), N);

    for (int i = 0; i < N; i++)
    {
        decay_arr[i] = time[i] / (1 - radioactivity[i]);
    }

    square_sum = 0;
    
    for (int i = 0; i < N; i++)
    {
        square_sum += decay_arr[i]*decay_arr[i];
    }

    decay_rate = sqrt(square_sum) / N;

    return decay_rate;
}

