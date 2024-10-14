#include <iostream>
#include <iomanip>
using namespace std;

float F(float x) {
    return x * x * (5 - x);
}

int main() {
    const int m = 5, n = 5; // Fixed values for m and n
    float u[n + 1][m + 1], r, h, k;

    cout << "Enter the value of delta x:\n";
    cin >> h;
    cout << "Enter the value of delta t:\n";
    cin >> k;
    
    r = ((k * k) / (h * h));

    // Initialize boundary conditions
    for (int j = 0; j <= m; j++) {
        u[0][j] = u[n][j] = 0; // Boundary conditions at y=0 and y=n
    }
    
    // Initial conditions
    for (int i = 1; i < n; i++) {
        u[i][0] = F(i * h); // Initial condition at t=0
        u[i][1] = u[i][0];  // u at t=k (initial velocity condition)
    }

    // Solve the wave equation
    for (int j = 1; j < m; j++) {
        for (int i = 1; i < n; i++) {
            /*u[i][j + 1] = 2 * (1 - r) * u[i][j] + r * (u[i - 1][j] + u[i + 1][j]) - u[i][j - 1];*/
            u[i][j+1]=u[i+1][j]+u[i-1][j]-u[i][j-1];
        }
    }

    // Output the results
    cout << fixed << setprecision(2);
    cout << "Solution of the Wave Equation is:\n";
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i <= n; i++) {
            cout << u[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
