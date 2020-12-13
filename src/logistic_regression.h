#ifndef LOGISTIC_REGRESSION_H
#define LOGISTIC_REGRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "util.h"

void graph();

void gradient_descent_logistic(REAL alpha, REAL** x, REAL* y);

void load_binary_data(char* path);

void train_logistic(REAL alpha, int tmax_);

#endif //LOGISTIC_REGRESSION_H