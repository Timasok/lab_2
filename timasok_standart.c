#include <math.h>
#include <stdio.h>
#include <string.h>

#include "timasok_standart.h"

const double EPS = 0.00001;

int equals(const double num_1, const double num_2)
{
    if (abs(num_1 - num_2) < EPS)
        return 1;

    return 0;

}
