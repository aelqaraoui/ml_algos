#ifndef MODEL_H
#define MODEL_H

#include "linear_regression.h"

#define LINEAR_REG 0
#define LOGISTIC_REG 1

int n;
int dim;
int type;

float** x;
float* y;
float* w;

float dot(float* a, float* b, int d);

float MSE(float** x, float* y, int m);

#endif //MODEL_H