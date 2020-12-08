#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "model.h"

void init_model(int d, int n_, int type_);

void graph();

void gradient_descent(float alpha, float** x, float* y);

void load_data(char* path);

void train(float alpha, int tmax_);

#endif //LINEAR_REGRESSION_H