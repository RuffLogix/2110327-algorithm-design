#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int solve(int n, int k, int mod = 1997) {
    if (k == 1) return 1;
    if (n < 1 || k > n) return 0;
    if (dp[n][k]) return dp[n][k];

    return dp[n][k] = (solve(n-1, k-1) + solve(n-1, k) * k) % mod;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << solve(n, k) << '\n';

    return 0;
}
