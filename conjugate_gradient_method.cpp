#include <iostream>
#include <Eigen/Sparse>

using namespace Eigen;

template <typename T>
VectorXd conjugateGradient(const SparseMatrix<T>& A, const VectorXd& b, const T tolerance = 1e-6, const int maxIterations = 500) {
    int n = A.rows();

    VectorXd x = VectorXd::Zero(n);
    VectorXd r = b - A * x;
    VectorXd p = r;
    
    for (int iter = 0; iter < maxIterations; ++iter) {
        T alpha = r.dot(r) / p.dot(A * p);
        
        x += alpha * p;
        r -= alpha * A * p;

        if (r.norm() < tolerance) {
            std::cout << "Converged after " << iter + 1 << " iterations.\n";
            break;
        }

        T beta = r.dot(r) / p.dot(A * p);

        p = r + beta * p;
    }

    return x;
}

int main() {
    int n = 100; // Dimension of the system
    SparseMatrix<double> A(n, n);
    A.setIdentity();

    // Add some random values to the matrix
    for (int i = 0; i < n/5; i++) {
        float random_val = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        int row = abs(std::rand() % n - 1);
        int loat col = abs(std::rand() % n - 1);

        A.coeffRef(row, col) = random_val/100;
        A.coeffRef(col, row) = random_val/100;
    }

    // Print the matrix A
    std::cout << "Matrix A:\n" << A << std::endl;

    VectorXd b = VectorXd::Ones(n); // b vector

    // Print the vector b
    std::cout << "Vector b:\n" << b << std::endl;

    // Call the conjugateGradient function
    VectorXd x = conjugateGradient(A, b);

    // Print the solution
    std::cout << "Solution x:\n" << x << std::endl;

    // std::cout << "\n" << A*x << std::endl;


    return 0;
}


