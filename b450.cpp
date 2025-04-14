#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<int>> mat;
    int size;
    
    Matrix(int n) {
        size = n;
        mat = vector<vector<int>>(n, vector<int>(n, 0));
    }

    // Matrix Multiplication
    Matrix operator*(const Matrix &other) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }
};

// Matrix Exponentiation Function
Matrix power(Matrix base, int exp) {
    Matrix result(base.size);
    
    // Identity Matrix
    for (int i = 0; i < base.size; i++)
        result.mat[i][i] = 1;

    while (exp > 0) {
        if (exp % 2 == 1) 
            result = result * base;
        base = base * base;
        exp /= 2;
    }
    return result;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (c == 1) {
        cout << (a+MOD)%MOD << endl;
        return 0;
    }
    if (c == 2) {
        cout << (b+MOD)%MOD<< endl;
        return 0;
    }

    Matrix M(2);
    M.mat = {{-1, 1}, {1, 0}};  // Transformation matrix
    
    M = power(M, c - 2);  // Exponentiate the matrix to (c-2)

    // Compute final value using matrix multiplication
    int result = (1LL * M.mat[0][0] * b + 1LL * M.mat[0][1] * a) % MOD;
    
    if (result < 0) result += MOD;  // Ensure positive result

    cout << result << endl;
    return 0;
}
