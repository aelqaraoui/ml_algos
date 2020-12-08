#include "model.h"

float dot(float* a, float* b, int d)
{
    float result = 0;
    for(int i = 0; i < d; i++)
    {
        result += a[i]*b[i];
    }
    return result;
}

float MSE(float** x, float* y, int m)
{
    float result = 0;
    for(int i = 0; i < m; i++)
    {
        result += pow(dot(w, x[i], dim+1) - y[i], 2);
    }
    return result/(float)m;
}