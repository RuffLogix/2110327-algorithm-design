#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int choc[11];

int solve(int n, int k) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n]) return dp[n];

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += solve(n - choc[i], k);
        ans %= 1000003;
    }

    return dp[n] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        cin >> choc[i];
    }

    cout << solve(n, k) << '\n';

    return 0;
}
