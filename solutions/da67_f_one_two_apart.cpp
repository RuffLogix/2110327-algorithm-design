#include <bits/stdc++.h>

using namespace std;

int dp[1000001][3];
bitset<1000001> visited[3];

int solve(int n, int x) {
    if (n == 0) return 1;
    if (x < 0) return 0;
    if (visited[x][n])
        return dp[n][x];

    visited[x][n] = true;
    if (x != 0) return dp[n][x] = (solve(n-1, 2) + solve(n-1, x-1)) % int(1e8 + 7);
    return dp[n][x] = (2 * solve(n-1, 2) + solve(n-1, 0)) % int(1e8 + 7);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    cout << solve(n, 0) << '\n';

    return 0;
}
