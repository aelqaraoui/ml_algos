#include "logistic_regression.h"

void gradient_descent_logistic(REAL alpha, REAL** x, REAL* y)
{
    REAL* wpl = (REAL*)malloc((dim+1)*sizeof(REAL));
    for(int j = 0; j < dim+1; j++)
    {
        REAL sum = 0;
        for(int i = 0; i < n; i++)
        {
            REAL pl = exp(-dot(w, x[i], dim+1));
            pl = (1.0f/(1.0f + pl));
            sum += (y[i] * x[i][j]) - (x[i][j] * pl);
        }

        wpl[j] = w[j] - alpha * (-1.0f/(REAL)n) * sum;
        
    }
    free(w);
    w = wpl;
}

void load_binary_data(char* path)
{
    char* line = NULL;
    FILE* cars;
    size_t len = 0;
    
    if(!(cars = fopen(path, "r")))
    {
        printf("Error loading data.\n");
    }
    getline(&line, &len, cars); 
    
    for(int i = 0; i < n; i++)
    {
        getline(&line, &len, cars); 
        line[strcspn(line, "\n")] = 0;
        char* save;
        y[i] = (REAL)atof(strtok_r(line, ",", &save));
        //printf("y=(%f) x(", (double)y[i]);
        for(int j = 0; j < dim; j++)
        {
            x[i][j] = atof(strtok_r(NULL, ",", &save));
            //printf("%f, ", (double)x[i][j]);
        }
        //printf("1)\n");
        x[i][dim] = 1.0f;
    }
}

void train_logistic(REAL alpha, int tmax_)
{
    REAL loss = CEL(x, y, n);
    printf("loss=%f w=(", (double)loss);
    for(int i = 0; i < dim; i++)  printf("%f,", (double)w[i]);
    printf("%f)\n", (double)w[dim]);

    FILE* floss;
    if(!(floss = fopen("res/loss.dat", "w")))
    {
        printf("Error writing loss data.\n");
    }
    int tmax = 0;
    fprintf(floss, "%f %f\n", (double)((REAL)tmax/(REAL)tmax_), (double)loss);
    while(loss > 0.0000001f && tmax < tmax_)
    {
        fprintf(floss, "%f %f\n", (double)((REAL)tmax/tmax_), (double)loss);
        gradient_descent_logistic(alpha, x, y);
        printf("loss=%f w=(", (double)loss);
        for(int i = 0; i < dim; i++)  printf("%f,", (double)w[i]);
        printf("%f)\n", (double)w[dim]);
        loss = CEL(x, y, n);
        tmax++;
    }
    printf("loss=%f w=(", (double)loss);
    for(int i = 0; i < dim; i++)  printf("%f,", (double)w[i]);
    printf("%f)\n", (double)w[dim]);
    fclose(floss);
}