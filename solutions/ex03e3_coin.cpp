#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int coins[21];

int solve(int n, int k) {
    if (k < 0) return 1e9;
    if (k == 0) return 0;
    if (dp[k]) return dp[k];

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, solve(n, k - coins[i]) + 1);
    }

    return dp[k] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    cout << solve(n, k) << '\n';

    return 0;
}
