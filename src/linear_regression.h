#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "util.h"

void graph();

void gradient_descent_linear(REAL alpha, REAL** x, REAL* y);

void load_data(char* path);

void train(REAL alpha, int tmax_);

#endif //LINEAR_REGRESSION_H