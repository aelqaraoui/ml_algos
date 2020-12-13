#define LINEAR_REG
#include "model.h"

int main()
{
    //Initializing model
    init_model(1, 50);

    //Loading training data
    load_data("res/cars.csv");

    //Train the model
    train(0.0001f, 100000);
    
    graph();

    return 0;
}