#include <iostream>
#include <string>
#include <tuple>

using namespace std;

float objective_function(float x){
    return x*x + 13 - 12*x;
}

tuple<float, float> bisection(float a, float b){
    // choose a,b s.t.:
    // f(a) \isin R+
    // f(b) \isin R-

    float c = (a+b)/2;

    if (objective_function(c) > 0) {
        a = c;
    } else if (objective_function(c) == 0){
        return make_tuple(c,c);
    } else {
        b=c;
    }

    return make_tuple(a, b);
}

int main(){
    int n_iter = 100;
    int iter = 0;

    float a = 1;
    float b = 4;
    tuple<float, float> result;

    while (iter < n_iter){
        result = bisection(a,b);

        a = get<0>(result);
        b = get<1>(result);
        
        iter++;
    }

    cout << "One root of the function is " << a << "\n";
    
    return 0;
}