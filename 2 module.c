#include <stdio.h>
#include <stdlib.h>

#include "radio.h"



double model(double *radioactivity, double *time, int N, double point)     // моделирование функции     
{
    for (int i = 0; i < N; i++)
    {
        if (equals(point, time[i])) return radioactivity[i];   
    }
}

double func_val (double *radioactivity, double *time, int N, double decay_time)
{
    sum = 0;

    for (i = 0, i < N; i++)
    {
        sum += time[i] * exp (-time[i]/decay_time) * (radioactivity[i] - exp (-time[i]/decay_time));
    }

    return sum;
}