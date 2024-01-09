#include <iostream>
using namespace std;

float iteration(float x, float num){
    float solution = (x + num/x)/2;
    return solution;
}

int main() {

    float eps = 1e-6;
    float num = 144;
    float x = num/2;

    int iter = 0;

    while (iter < 100) {
        x = iteration(x, num);

        iter++;
    }

    cout << x << " is the square root of " << num <<"\n";

    return 0;
}
