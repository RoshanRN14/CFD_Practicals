#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 4; // Fixed grid size for 4x4 matrix

// Function to perform the Gauss-Seidel iteration for 2D Laplace equation
void gaussSeidel(float u[SIZE][SIZE], int iterations) {
    for (int iter = 0; iter < iterations; ++iter) {
        // Update values using Gauss-Seidel iteration for all points
        for (int i = 1; i < SIZE - 1; ++i) {
            for (int j = 1; j < SIZE - 1; ++j) {
                // Update u[i][j] in place using the Gauss-Seidel formula
                u[i][j] = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1]);
            }
        }

        // Print the matrix after each iteration
        cout << "Iteration " << iter + 1 << ":\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << fixed << setprecision(2) << setw(7) << u[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main() {
    int iterations;
    float u[SIZE][SIZE];

    cout << "Enter the number of iterations: ";
    cin >> iterations;

    // Input boundary conditions
    cout << "Enter the boundary conditions:\n";
    
    cout << "Top boundary (4 values): ";
    for (int j = 0; j < SIZE; ++j) {
        cin >> u[0][j]; // Top row
    }

    cout << "Bottom boundary (4 values): ";
    for (int j = 0; j < SIZE; ++j) {
        cin >> u[SIZE - 1][j]; // Bottom row
    }

    cout << "Left middle boundary (2 values): ";
    for (int i = 1; i < SIZE - 1; ++i) {
        cin >> u[i][0]; // Left column
    }

    cout << "Right middle boundary (2 values): ";
    for (int i = 1; i < SIZE - 1; ++i) {
        cin >> u[i][SIZE - 1]; // Right column
    }

    // Initialize interior points to zero
    for (int i = 1; i < SIZE - 1; ++i) {
        for (int j = 1; j < SIZE - 1; ++j) {
            u[i][j] = 0.0;
        }
    }

    // Solve using Gauss-Seidel iteration
    gaussSeidel(u, iterations);

    return 0;
}
