#include "timasok_standart.h"
//Michael
int experiment (double *radioactivity, double *time, double start_time, double end_time, double step);
void add_noise (double *radioactivity, int N);

//artemKa
double nonlinear_equation (double *radioactivity, double *time, int N, double precision);
double model(double *radioactivity, double *time, int N, double point);
double linear_equation (double *radioactivity, double *time, int N);

//Brick
double precision_analysis (double *radioactivity, double *time, int N);
double dev_exp(double *radioactivity, double *time, int M, double decay_time);
double dev_linear(double *radioactivity, double *time, int M, double decay_rate);