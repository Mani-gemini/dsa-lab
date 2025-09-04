#include <iostream>
using namespace std;

// (a) Diagonal Matrix
void diagonalMatrix(int n) {
    int A[n];   // only n elements
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << A[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (b) Tri-diagonal Matrix
void triDiagonalMatrix(int n) {
    int A[3*n - 2];  // lower, main, upper diagonals
    cout << "Enter " << (3*n-2) << " elements (lower, main, upper): ";
    for (int i = 0; i < 3*n-2; i++) cin >> A[i];

    cout << "Tri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i-j == 1) cout << A[i-1] << " ";          // lower
            else if (i-j == 0) cout << A[n-1 + i] << " "; // main
            else if (i-j == -1) cout << A[2*n-1 + i] << " "; // upper
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (c) Lower Triangular Matrix
void lowerTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    cout << "Enter " << size << " elements (row-wise lower): ";
    for (int i = 0; i < size; i++) cin >> A[i];

    cout << "Lower Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << A[i*(i+1)/2 + j] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (d) Upper Triangular Matrix
void upperTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    cout << "Enter " << size << " elements (row-wise upper): ";
    for (int i = 0; i < size; i++) cin >> A[i];

    cout << "Upper Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                int index = i*n - (i*(i-1))/2 + (j - i);
                cout << A[index] << " ";
            }
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (e) Symmetric Matrix (store lower triangle only)
void symmetricMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    cout << "Enter " << size << " elements (lower triangle row-wise): ";
    for (int i = 0; i < size; i++) cin >> A[i];

    cout << "Symmetric Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << A[i*(i+1)/2 + j] << " ";
            else cout << A[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    diagonalMatrix(n);
    triDiagonalMatrix(n);
    lowerTriangularMatrix(n);
    upperTriangularMatrix(n);
    symmetricMatrix(n);

    return 0;
}
