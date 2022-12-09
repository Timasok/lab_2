#include <stdio.h>
#include <stdlib.h>

#include "radio.h"

int main()
{
    double step = 0.1;
    double start_time = 0; 
    double end_time = 9.9; 

    int elements_number = end_time/step;

    double * radioactivity = (double *)calloc(elements_number, sizeof(double));
    double * time = (double *)calloc(elements_number, sizeof(double));

    printf("EXPERIMENT\n");

    experiment(radioactivity, time, start_time, end_time, step);
    print_data(radioactivity, time, elements_number);

    printf("dec_time dec_rate\n");

    double decay_time = nonlinear_equation(radioactivity, time, elements_number, PRECISION);
    double decay_rate = linear_equation(radioactivity, time, elements_number);

    printf("decay_time = %lf decay_rate = %lf\n", decay_time, decay_rate);

    // printf("delta_t = %lf\n", precision_analysis(radioactivity, time, elements_number));

    free(time);
    free(radioactivity);
    return 0;
    
}