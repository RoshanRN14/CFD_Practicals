#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 4; // Fixed grid size for 4x4 matrix

// Function to perform the Jacobi iteration for 2D Laplace equation
void jacobi(float u[SIZE][SIZE], int iterations) {
    float u_new[SIZE][SIZE];
    
    for (int iter = 0; iter < iterations; ++iter) {
        // Copy current values to u_new
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                u_new[i][j] = u[i][j];
            }
        }

        // Jacobi iteration update for interior points
        for (int i = 1; i < SIZE - 1; ++i) {
            for (int j = 1; j < SIZE - 1; ++j) {
                u_new[i][j] = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1]);
            }
        }

        // Copy new values back to u
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                u[i][j] = u_new[i][j];
            }
        }

        // Print matrix after each iteration
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
    float u[SIZE][SIZE] = {0};

    cout << "Enter the number of iterations: ";
    cin >> iterations;

    // Input boundary conditions
    cout << "Enter top boundary (4 values): ";
    for (int j = 0; j < SIZE; ++j) {
        cin >> u[0][j]; // Top row
    }

    cout << "Enter bottom boundary (4 values): ";
    for (int j = 0; j < SIZE; ++j) {
        cin >> u[SIZE - 1][j]; // Bottom row
    }

    cout << "Enter left boundary (2 values): ";
    for (int i = 1; i < SIZE - 1; ++i) {
        cin >> u[i][0]; // Left column
    }

    cout << "Enter right boundary (2 values): ";
    for (int i = 1; i < SIZE - 1; ++i) {
        cin >> u[i][SIZE - 1]; // Right column
    }

    // Solve using Jacobi iteration
    jacobi(u, iterations);

    return 0;
}
