#include <iostream>
#include <iomanip>
using namespace std;

float x[10];

// Thomas algorithm for tridiagonal matrix solution
float* tridiagonal(float a, float b, float c, float d[], int n) {
    int i;
    float alpha[10], beta[10];
    
    // Initialize the first entries
    alpha[1] = b;
    beta[1] = d[1] / b;
    
    // Forward elimination
    for (i = 2; i < n - 1; i++) {
        alpha[i] = b - (a * c / alpha[i - 1]);
        beta[i] = (d[i] - a * beta[i - 1]) / alpha[i];
    }

    // Back substitution
    x[n - 2] = beta[n - 2];
    for (i = n - 3; i >= 1; i--) {
        x[i] = beta[i] - (c * x[i + 1]) / alpha[i];
    }

    return x;
}

int main() {
    int i, j, n = 8, m = 5;
    float u[100][100], r = 0.5;

    // Boundary and initial conditions
    for (j = 0; j <= m; j++) {
        u[0][j] = 0;
        u[n][j] = 0;
    }
    for (i = 1; i < n; i++) {
        u[i][0] = (i * (8 - i)) / 2.0;  // Initial temperature distribution
    }

    float a = -r, b = (1 + 2 * r), c = -r;
    float d[n];

    for (j = 0; j < m; j++) {
        // Set up the right-hand side for the implicit scheme at time step j
        for (i = 1; i < n - 1; i++) {
            d[i] = u[i][j];  // Right-hand side is u[i][j] from previous time level
        }

        // Solve the tridiagonal system for the next time step
        float* y = tridiagonal(a, b, c, d, n);

        // Store results for the next time step in u
        for (i = 1; i < n - 1; i++) {
            u[i][j + 1] = y[i];
        }
    }

    // Output the result
    cout << "The value of all u(i,j):\n";
    cout << fixed << setprecision(4);
    for (j = m; j >= 0; j--) {
        for (i = 0; i <= n; i++) {
            cout << "\t" << u[i][j];
        }
        cout << endl;
    }

    return 0;
}
