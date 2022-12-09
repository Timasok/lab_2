#ifndef KIRPICH_H
#define KIRPICH_H

double precision_analysis( double *radioactivity, double *time, int N );
double dev_exp( double *radioactivity, double *time, int M, double decay_time );
double dev_linear( double *radioactivity, double *time, int M, double decay_rate );

#endif