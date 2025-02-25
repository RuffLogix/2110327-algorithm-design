#include <bits/stdc++.h>

using namespace std;

int dp[31][31][31][2];
bitset<31> visited[31][31][2];

int solve(int n, int cm, int k, int m, int pre) {
    if (n == 0 && k == 0 && pre == 0 && cm >= 0) return 1;
    if (n == 0 || cm < 0) return 0;
    if (visited[n][cm][pre][k]) return dp[n][cm][k][pre];
    visited[n][cm][pre][k] = true;
    return dp[n][cm][k][pre] = solve(n-1, cm-1, k, m, pre) + solve(n-1, m-1, k-1, m, 1-pre);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    cout << solve(n-1, m-1, k, m, 0) + solve(n-1, m-1, k, m, 1) << '\n';

    return 0;
}
