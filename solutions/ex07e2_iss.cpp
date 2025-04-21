#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

int solve(int n, int pre) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n][pre]) return dp[n][pre];

    int ans = 0;
    for (int i = 1; i <= pre; i++) {
        ans += solve(n-i, i);
    }
    return dp[n][pre] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    cout << solve(n, n) << '\n';

    return 0;
}
