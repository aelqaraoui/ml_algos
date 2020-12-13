#include "linear_regression.h"

void graph()
{
    FILE* fptr;
    if(!(fptr = fopen("res/points.dat", "w")))
    {
        printf("Error writing points.\n");
    }
    for(int i = 0; i < n; i++)
    {
        REAL xpl = x[i][0];
        REAL ypl = y[i];
        fprintf(fptr, "%f %f\n", (double)xpl, (double)ypl);
    }
    fclose(fptr);

    FILE* fptr1;
    if(!(fptr1 = fopen("res/line.dat", "w")))
    {
        printf("Error\n");
    }
    fprintf(fptr1, "%f %f\n%f %f\n", 0.0f, (double)w[dim], 1.0f, (double)(w[0]+w[dim]));
    fclose(fptr1);

    char command[1024] = "gnuplot -e \"set terminal png size 400,300; set output 'points.png'; plot 'res/points.dat' with points notitle, 'res/line.dat' with lines notitle";
    char command2[256];
    sprintf(command2, ", (%f)*x + (%f) notitle\"", (double)w[0], (double)w[dim]);
    strcat(command, command2);
    system(command);
    system("gnuplot -e \"set terminal png size 400, 300; set output 'loss.png'; set style line 100; plot 'res/loss.dat' with lines lw 2 notitle\"");

}

void gradient_descent_linear(REAL alpha, REAL** x, REAL* y)
{
    REAL* wpl = (REAL*)malloc((dim+1)*sizeof(REAL));
    for(int j = 0; j < dim+1; j++)
    {
        REAL sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += (dot(w, x[i], dim+1) - y[i]) * x[i][j];
        }

        wpl[j] = w[j] - alpha * (2.0/(REAL)n) * sum;
        
    }
    free(w);
    w = wpl;
}

void load_data(char* path)
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
        x[i][0] = (REAL)atof(strtok_r(line, ",", &save));
        for(int j = 1; j < dim; j++)
        {
            x[i][j] = atof(strtok_r(NULL, ",", &save));
        }
        x[i][dim] = 1.0f;
        y[i] = atof(strtok_r(NULL, ",", &save));
    }
}

void train(REAL alpha, int tmax_)
{
    REAL loss = MSE(x, y, n);
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
        gradient_descent_linear(alpha, x, y);
        printf("loss=%f w=(", (double)loss);
        for(int i = 0; i < dim; i++)  printf("%f,", (double)w[i]);
        printf("%f)\n", (double)w[dim]);
        loss = MSE(x, y, n);
        tmax++;
    }
    printf("loss=%f w=(", (double)loss);
    for(int i = 0; i < dim; i++)  printf("%f,", (double)w[i]);
    printf("%f)\n", (double)w[dim]);
    fclose(floss);
}