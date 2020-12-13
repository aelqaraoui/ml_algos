#include "model.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "util.h"

void init_model(int d, int n_)
{
    dim = d;
    n = n_;
    x = (REAL**)malloc(n*sizeof(REAL*));
    y = (REAL*)malloc(n*sizeof(REAL));
    w = (REAL*)malloc((dim+1)*sizeof(REAL));
    for(int i = 0; i < n; i++)
    {
        x[i] = (REAL*)malloc((dim+1)*sizeof(REAL));
    }
    for(int i = 0; i < dim+1; i++)
    {
        w[i] = (REAL)rand()/(REAL)RAND_MAX;
    }
    
}