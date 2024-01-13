#include <iostream>
#include <cmath>
#include <Eigen/Sparse>

using namespace Eigen;

template <typename T>
VectorXd bicg(const SparseMatrix<T>& A, const VectorXd& b, const T tolerance = 1e-10, const int maxIterations = 5000) {
    int n = A.rows();

    VectorXd x = VectorXd::Zero(n);
    VectorXd r = b - A * x;
    VectorXd r_tilde = r;
    VectorXd p = r;
    VectorXd p_tilde = r_tilde;

    VectorXd r_old = r;
    VectorXd r_old_tilde = r_tilde;

    for (int iter = 0; iter < maxIterations; ++iter) {
        T alpha = r.dot(r_tilde) / (p_tilde.dot(A * p));

        x += alpha * p;
        r -= alpha * (A * p);
        r_tilde -= alpha * A.transpose() * p_tilde;

        T beta = r.dot(r_tilde) / (r_old.dot(r_old_tilde));

        p = r + beta * p;
        p_tilde = r_tilde + beta * p_tilde;

        if (r_tilde.norm() < tolerance) {
            std::cout << "Converged after " << iter + 1 << " iterations.\n";
            break;
        }

        r_old = r;
        r_old_tilde = r_tilde;
    }

    return x;
}

int main() {
    int n = 100; // Dimension of the system
    SparseMatrix<double> A(n, n);
    A.setIdentity();

    // Modify matrix A with random values
    for (int i = 0; i < n/5; i++) {
        float random_val = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        int row = std::abs(std::rand() % n - 1);
        int col = std::abs(std::rand() % n - 1);

        A.coeffRef(row, col) = random_val/100;
    }

    // Print the matrix A
    std::cout << "Matrix A:\n" << A << std::endl;

    VectorXd b = VectorXd::Ones(n); // b vector

    // Print the vector b
    std::cout << "Vector b:\n" << b << std::endl;

    // Call the bicg function
    VectorXd x = bicg(A, b);

    // Print the solution
    std::cout << "Solution x:\n" << x << std::endl;

    // std::cout << "\n" << A*x << std::endl;

    return 0;
}
