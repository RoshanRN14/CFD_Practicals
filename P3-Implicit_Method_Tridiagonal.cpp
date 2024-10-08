#include <iostream>
#include <iomanip>

using namespace std;

float x[10];

float* tridiagonal(float r, float d[], int n) {
    int i;
    float a = -r, b = (1 + 2 * r), c = -r;
    float alpha[10], beta[10];
    alpha[1] = b;
    beta[1] = d[1] / b;
    for (i = 2; i < n; i++) {
        alpha[i] = b - (a * c / alpha[i - 1]);
        beta[i] = (d[i] - a * beta[i - 1]) / alpha[i];
    }
    x[n - 1] = beta[n - 1];
    for (i = n - 2; i >= 1; i--) {
        x[i] = beta[i] - (c * x[i + 1]) / alpha[i];
    }
    return x;
}

int main() {
    int i, j, n, m;
    float u[100][100], c, r;

    cout << "Enter the value of c: ";
    cin >> c;
    cout << "Enter the value of r: ";
    cin >> r;
    cout << "Enter the value of m: ";
    cin >> m;
    cout << "Enter the value of n: ";
    cin >> n;

    for (j = 0; j <= m; j++) {
        u[0][j] = 100;
        u[n][j] = 50;
    }

    for (i = 1; i < n; i++) {
        u[i][0] = 0;
    }

    float d[10];
    for (j = 0; j < m; j++) {
        for (i = 1; i < n; i++) {
            d[i] = r * u[i - 1][j + 1] + (1 - 2 * r) * u[i][j + 1] + r * u[i + 1][j + 1];
        }
        float* y = tridiagonal(r, d, n);
        for (i = 1; i < n; i++) {
            u[i][j + 1] = y[i];
        }
    }

    cout << "The value of all u(i,j):\n";
    cout << fixed << setprecision(4); // Setting precision to 2 decimal places
    for (j = m; j >= 0; j--) {
        for (i = 0; i <= n; i++) {
            cout << u[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
