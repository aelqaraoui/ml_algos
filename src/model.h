#ifndef MODEL_H
#define MODEL_H

void init_model(int d, int n_);

#ifdef LINEAR_REG
    #include "linear_regression.h"
#endif

#ifdef LOGISTIC_REG
    #include "logistic_regression.h"
#endif

#endif //MODEL_H