#include <iostream>
#include <vector>

bool isMonotone(const std::vector<std::vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Check row-wise monotonicity
    for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] < matrix[i][j - 1]) {
                return false;
            }
        }
    }

    return true; // Matrix is monotnic along rows
}

int main() {
    std::vector<std::vector<double>> monotoneMatrix = {
        {0.1, 0.3, 0.6},
        {0.2, 0.5, 0.7},
        {0.0, 0.2, 0.8}
    };

    // Check the matrix for row-wise monotonicity
    if (isMonotone(monotoneMatrix)) {
        std::cout << "The matrix is monotonic along rows." << std::endl;
    } else {
        std::cout << "The matrix is not monotonic along rows." << std::endl;
    }

    std::vector<std::vector<double>> nonMonotoneMatrix = {
        {0.1, 0.6, 0.3},
        {0.2, 0.5, 0.7},
        {0.0, 0.2, 0.8}
    };

    // Check the matrix for row-wise monotonicity
    if (isMonotone(nonMonotoneMatrix)) {
        std::cout << "The matrix is monotonic along rows." << std::endl;
    } else {
        std::cout << "The matrix is not monotonic along rows." << std::endl;
    }

    return 0;
}
