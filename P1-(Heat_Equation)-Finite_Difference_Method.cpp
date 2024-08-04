#include <iostream>

using namespace std;

float f(float x) {
    return 4 *x - (x*x)/2;
}

int main() {
    int m, n;
    float h, k, c, u[20][20], r;
    h=1;
    k=0.125;
    cout << "Enter the values of c, m, n:\n";
    cin >>c >> m >> n;

    // Initialize boundary conditions
    for (int j = 0; j <= m; j++) {
        u[0][j] = 0;
        u[n][j] = 0;
    }

    // Initialize initial conditions
    for (int i = 1; i < n; i++) {
        u[i][0] = f(i * h);
    }

    // Compute r
    r = (c * c * k) / (h * h);

    // Compute solution using finite difference method
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            u[i][j + 1] = r * (u[i - 1][j] + u[i + 1][j]) + (1 - 2 * r) * u[i][j];
        }
    }

    // Print the solution of the heat equation
    cout << "\nSolution of the heat equation:\n";
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i <= n; i++) {
            cout << u[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
