#include <bits/stdc++.h>

using namespace std;

#define Matrix vector<vector<int>>

Matrix add_matrix(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix sub_matrix(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

void split_matrix(Matrix &A, Matrix &A11, Matrix &A12, Matrix &A21, Matrix &A22) {
    int n = A.size() >> 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+n];
            A21[i][j] = A[i+n][j];
            A22[i][j] = A[i+n][j+n];
        }
    }
}

Matrix strassen(Matrix A, Matrix B) {
    if (A.size() == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int n = A.size() >> 1;
    Matrix A11(n, vector<int>(n)), A12(n, vector<int>(n)), A21(n, vector<int>(n)), A22(n, vector<int>(n));
    Matrix B11(n, vector<int>(n)), B12(n, vector<int>(n)), B21(n, vector<int>(n)), B22(n, vector<int>(n));
    Matrix C(n << 1, vector<int>(n << 1));

    split_matrix(A, A11, A12, A21, A22);
    split_matrix(B, B11, B12, B21, B22);

    Matrix M1 = strassen(add_matrix(A11, A22), add_matrix(B11, B22));
    Matrix M2 = strassen(add_matrix(A21, A22), B11);
    Matrix M3 = strassen(A11, sub_matrix(B12, B22));
    Matrix M4 = strassen(A22, sub_matrix(B21, B11));
    Matrix M5 = strassen(add_matrix(A11, A12), B22);
    Matrix M6 = strassen(sub_matrix(A21, A11), add_matrix(B11, B12));
    Matrix M7 = strassen(sub_matrix(A12, A22), add_matrix(B21, B22));

    Matrix C11 = add_matrix(sub_matrix(add_matrix(M1, M4), M5), M7);
    Matrix C12 = add_matrix(M3, M5);
    Matrix C21 = add_matrix(M2, M4);
    Matrix C22 = add_matrix(sub_matrix(add_matrix(M1, M3), M2), M6);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = C11[i][j];
            C[i][j+n] = C12[i][j];
            C[i+n][j] = C21[i][j];
            C[i+n][j+n] = C22[i][j];
        }
    }

    return C;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);    

    Matrix A = {{1, 2, 4, 9}, {1, 2, 4, 9}, {1, 2, -4, 9}, {1, 2, 4, 9}};
    Matrix B = {{1, 2, 3, 9}, {1, 1, 4, 9}, {-1, 2, 4, 9}, {1, 2, -4, 11}};
    Matrix C = strassen(A, B);

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C.size(); j++) {
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}