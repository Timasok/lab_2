#include "radio.h"

double nonlinear_equation (double *radioactivity, double *time, int N, double precision) // аппроксимация нелинейной функции
{
    double decay_time = 0;
    
    double* decay_arr = (double*) calloc (N, sizeof(double));

    for (int i = 1; i < N; i++)
    {
        decay_arr[i] = -time[i] / log(radioactivity[i]);
        // printf("decay_arr[%d] = %lf\n", i, decay_arr[i]);
    }

    double square_sum = 0;
    
    for (int i = 1; i < N; i++)
    {
        // printf("decay_arr[%d] = %lf\n", i, decay_arr[i]);
        // printf("square_sum = %lf\n", square_sum);

        square_sum += decay_arr[i]*decay_arr[i] ;

    }

    decay_time = 10*sqrt(square_sum) / N;

    // printf("decay time = %lf square_sum = %lf\n", decay_time, square_sum);
    free(decay_arr);

    return decay_time;
}

double model(double *radioactivity, double *time, int N, double point)     // моделирование функции     
{
    for (int i = 1; i < N; i++)
    {
        if (equals(point, time[i])) return radioactivity[i];   
    }
}

double linear_equation (double *radioactivity, double *time, int N) // аппроксимация линейной функции
{
    double decay_rate = 0;
    
    double* decay_arr = (double*) calloc (sizeof(double), N);

    for (int i = 1; i < N; i++)
    {
        decay_arr[i] = time[i] / (1 - radioactivity[i]);
    }

    double square_sum = 0;
    
    for (int i = 1; i < N; i++)
    {
        square_sum += decay_arr[i]*decay_arr[i];
    }

    decay_rate = 11.7 * sqrt(square_sum) / N;

    return decay_rate;
}

