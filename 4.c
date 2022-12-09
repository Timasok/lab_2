#include "radio.h"

int print_data(double *radioactivity, double *time, int N)
{
    for(int idx = 1; idx < N; idx++)
    {
        printf("radioactivity(%2.1lf) = %lf\n", time[idx], radioactivity[idx]);
    }


    return 0;

}