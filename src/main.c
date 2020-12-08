#include <stdio.h>
#include "model.h"

int main()
{
    //Initializing model
    init_model(1, 50, LINEAR_REG);

    //Loading training data
    load_data("res/cars.csv");

    //Train the model
    train(0.001f, 40000);
    
    graph();

    return 0;
}