#include <bits/stdc++.h>

using namespace std;

struct Matrix {
    int arr[2][2];
    int m;

    Matrix () { }
    Matrix (int k): m(k) { }

    Matrix operator * (Matrix &rhs) {
        Matrix res(m);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.arr[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.arr[i][j] += (arr[i][k]%m * rhs.arr[k][j]%m) % m;
                    res.arr[i][j] %= m;
                }
            }
        }
        return res;        
    }
};

Matrix solve(Matrix A, int n) {
    if (n == 0) {
        Matrix iden(A.m);
        iden.arr[0][0] = 1; 
        iden.arr[0][1] = 0;
        iden.arr[1][0] = 0;
        iden.arr[1][1] = 1;
        return iden;
    }
    if (n == 1) return A;
    Matrix ans = solve(A, n/2);
    return (n%2) ? ans * ans * A : ans * ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    Matrix A(k);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A.arr[i][j];
        }
    }

    A = solve(A, n);

   for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << A.arr[i][j] << ' ';
        }
    } 

    return 0;
}