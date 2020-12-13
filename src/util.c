#include "util.h"
#include <math.h>
#include <assert.h>

REAL dot(REAL* a, REAL* b, int d)
{
    REAL result = 0;
    for(int i = 0; i < d; i++)
    {
        result += a[i]*b[i];
    }
    return result;
}

REAL MSE(REAL** x, REAL* y, int m)
{
    REAL result = 0;
    for(int i = 0; i < m; i++)
    {
        result += pow(dot(w, x[i], dim+1) - y[i], 2);
    }
    return result/(REAL)m;
}

REAL CEL(REAL** x, REAL* y, int m)
{
    REAL result = 0;
    for(int i = 0; i < m; i++)
    {
        REAL pl = 1.0/(1.0 + exp(-dot(w, x[i], dim+1)));
        assert(pl < 1.0);
        result += (-y[i] * log(pl)) - ((1.0-y[i]) * log(1.0 - pl));
    }
    
    return result/(REAL)m;
}