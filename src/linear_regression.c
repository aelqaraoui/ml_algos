#include "linear_regression.h"

void init_model(int d, int n_, int type_)
{
    dim = d;
    n = n_;
    type = type_;
    x = (float**)malloc(n*sizeof(float*));
    y = (float*)malloc(n*sizeof(float));
    w = (float*)malloc((dim+1)*sizeof(float));
    for(int i = 0; i < n; i++)
    {
        x[i] = (float*)malloc((dim+1)*sizeof(float));
    }
    for(int i = 0; i < dim+1; i++)
    {
        w[i] = (float)rand()/(float)RAND_MAX;
    }
    
}

void graph()
{
    FILE* fptr;
    if(!(fptr = fopen("res/points.dat", "w")))
    {
        printf("Error writing points.\n");
    }
    for(int i = 0; i < n; i++)
    {
        float xpl = x[i][0];
        float ypl = y[i];
        fprintf(fptr, "%f %f\n", xpl, ypl);
    }
    fclose(fptr);

    FILE* fptr1;
    if(!(fptr1 = fopen("res/line.dat", "w")))
    {
        printf("Error\n");
    }
    fprintf(fptr1, "%f %f\n%f %f\n", 0.0f, w[dim], 1.0f, w[0]+w[dim]);
    fclose(fptr1);

    char command[1024] = "gnuplot -e \"set terminal png size 400,300; set output 'points.png'; plot 'res/points.dat' with points notitle, 'res/line.dat' with lines notitle";
    char command2[256];
    sprintf(command2, ", (%f)*x + (%f) notitle\"", w[0], w[dim]);
    strcat(command, command2);
    system(command);
    system("gnuplot -e \"set terminal png size 400, 300; set output 'loss.png'; set style line 100; plot 'res/loss.dat' with lines lw 2 notitle\"");

}

void gradient_descent(float alpha, float** x, float* y)
{
    float* wpl = (float*)malloc((dim+1)*sizeof(float));
    for(int j = 0; j < dim+1; j++)
    {
        if(type == LINEAR_REG)
        {
            float sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += (dot(w, x[i], dim+1) - y[i]) * x[i][j];
            }

            wpl[j] = w[j] - alpha * (2.0/(float)n) * sum;
        }
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
        x[i][0] = (float)atoi(strtok_r(line, ",", &save));
        for(int j = 1; j < dim; j++)
        {
            x[i][j] = (float)atoi(strtok_r(NULL, ",", &save));
        }
        x[i][dim] = 1.0f;
        y[i] = (float)atoi(strtok_r(NULL, ",", &save));
    }
}

void train(float alpha, int tmax_)
{
    float loss = MSE(x, y, n);
    printf("loss=%f w=(%f, %f)\n", loss, w[0], w[1]);

    FILE* floss;
    if(!(floss = fopen("res/loss.dat", "w")))
    {
        printf("Error writing loss data.\n");
    }
    int tmax = 0;
    fprintf(floss, "%f %f\n", (float)tmax/(float)tmax_, loss);
    while(loss > 0.0000001f && tmax < tmax_)
    {
        fprintf(floss, "%f %f\n", (float)tmax/50000.0, loss);
        gradient_descent(alpha, x, y);
        printf("loss=%f w=(%f, %f)\n", loss, w[0], w[1]);
        loss = MSE(x, y, n);
        tmax++;
    }
    printf("loss=%f w=(%f, %f)\n", loss, w[0], w[1]);
    fclose(floss);
}