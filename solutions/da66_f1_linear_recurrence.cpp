#include <bits/stdc++.h>

using namespace std;

// Overpower approach
struct Matrix {
    int n, m;
    vector<vector<long long>> arr;    

    Matrix() { }
    Matrix(int n): n(n), m(n) {
        arr.resize(n, vector<long long>(m, 0));
        for (int i=0; i<n; i++) arr[i][i] = 1;
    }
    Matrix(int n, int m): n(n), m(m) {
        arr.resize(n, vector<long long>(m, 0));
    }

    Matrix operator* (Matrix &rhs) const {
        Matrix ans(n, rhs.m);
		long long mod = 32717LL;
        for (int i=0; i<n; i++) {
            for (int j=0; j<rhs.m; j++) {
                for (int k=0; k<m; k++) {
                    ans.arr[i][j] += (arr[i][k]%mod) * (rhs.arr[k][j]%mod);
					ans.arr[i][j] += mod;
					ans.arr[i][j] %= mod;
                }
            }
        }
        return ans;
    }
};

Matrix mat_pow(Matrix &mat, int n) {
    if (n == 0) return Matrix(n);
    if (n == 1) return mat;
    Matrix ans = mat_pow(mat, n/2);
    return n%2==0 ? ans * ans : ans * ans * mat;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> k >> n;

	Matrix mat(k, k), v(k, 1);
	for (int i = 1; i <= k; i++) cin >> mat.arr[0][i-1];
	for (int i = 1; i <= k-1; i++) mat.arr[i][i-1] = 1;
	for (int i = 1; i <= k; i++) cin >> v.arr[k-i][0];

	if (n < k) {
		cout << v.arr[k-n-1][0] << '\n';
	} else {
		cout << (mat_pow(mat, n-k+1) * v).arr[0][0] << '\n';
	}

    return 0;
}