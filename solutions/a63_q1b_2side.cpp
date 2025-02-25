#include <bits/stdc++.h>

using namespace std;

int l[200001];
int r[200001];
int dp[200001][51][2];
bitset<200001> visited[51][2];

int solve(int n, int w, int k, int pre, bool flag = 1) {
    if (k < 0) return -1e9;
    if (n <= 0) return 0;
    if (visited[flag ? 0 : k][pre][n]) return dp[n][flag ? 0 : k][pre];

    int r1 = solve(n-1, w, k, pre, flag);
    int r2 = solve(n-w-1, w, k-1, 1-pre, flag) + (pre ? l[n] : r[n]);

    visited[flag ? 0 : k][pre][n] = true;
    return dp[n][flag ? 0 : k][pre] = max(r1, r2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, w, k;
    cin >> n >> w >> k;

    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];

    int ans = max(solve(n, w, k, 0, k == n), solve(n, w, k, 1, k == n));

    cout << ans << '\n';

    return 0;
}
