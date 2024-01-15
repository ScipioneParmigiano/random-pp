#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double monteCarloIntegration(int numSamples) {
    // Seed the random number generator
    srand(time(0));

    // Initialize the count of points inside the unit circle
    int insideCircleCount = 0;

    // Perform random sampling
    for (int i = 0; i < numSamples; ++i) {
        // Generate random coordinates in the range [-1, 1]
        double x = (2.0 * rand() / RAND_MAX) - 1.0;
        double y = (2.0 * rand() / RAND_MAX) - 1.0;

        // Check if the point is inside the unit circle
        if (x * x + y * y <= 1.0) {
            insideCircleCount++;
        }
    }

    // Estimate the area of the unit circle using Monte Carlo integration
    double estimatedArea = static_cast<double>(insideCircleCount) / numSamples;

    // Multiply by 4 to get the total area of the circle (as it is in the unit square)
    return 4.0 * estimatedArea;
}

int main() {
    // Number of Monte Carlo samples
    int numSamples = 1000000;

    // Perform Monte Carlo integration and print the result
    double result = monteCarloIntegration(numSamples);
    cout << "Monte Carlo Integration Result: " << result << endl;

    return 0;
}