int experiment(double* radioactivity, double* time, double start_time, double end_time, double step)
{
    double beta = end_time / 2;

    int N = (end_time - start_time) / step;
    double R_0 = 1;

    for (int i = 0; i < N; ++i)
    {
        time[i] = i * step;

        radioactivity[i] = R_0 * exp((-1) * time[i] / beta);
    }
   
}

void add_noise(double* radioactivity, int N)
{
    srand(time(NULL));

    for (int i = 0; i < N; ++i)
    {
        int r = (rand() % 2000000 - 1000000) / 1000000;
        radioactivity[i] += r;
    }
    
}
