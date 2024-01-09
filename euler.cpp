#include <iostream>
#include <vector>
#include <string>

using namespace std;

float function(float t, float y){
    return y;
}

int main()
{
    float y0 = 1; 
    float h = 0.1;
    float t = 0;
    vector<float> result;
    result.push_back(y0);

    for (int iter = 0; iter < 10; iter++)
    {   
        t+=h;
        float val = result[iter] + h * function(t, result[iter]);
        result.push_back(val);

        cout << result[iter] << " \n";
    }

    return 0;
}