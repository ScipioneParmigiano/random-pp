#include <iostream>

using namespace std;

float objective_function(float x){
    return x*x + 13 - 12*x;
}

float derivative(float x){
    // derivative of the objective function
    return 2*x - 12;
}

int main(){
    float x_new = 10;
    float x_old = -1;

    int n_iter = 1000;
    int iter = 0;

    float tol = 1e-6;

    while (iter < n_iter) {
        x_new = x_old - objective_function(x_old)/derivative(x_old);

        if(objective_function(x_old) - objective_function(x_new) < tol){
            break;
        }

        x_old = x_new;
        iter++;
    }
    cout << "One root of the function is: " << x_new << "\n";
    return 0;
}