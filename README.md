# Machine Learning Algorithms
All machine learning models here are implemented in C from scratch.
<br />
## Regression
| Linear Regression with Gradient Descent | Evolution of loss |
|----|----|
|<img src="https://github.com/aelqaraoui/ml_algos/blob/master/points.png" />|<img src="https://github.com/aelqaraoui/ml_algos/blob/master/loss.png" />|

## Compiling
To compile and run the code
```bash
$ make
$ make exec
```

## Usage
```C
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
```
