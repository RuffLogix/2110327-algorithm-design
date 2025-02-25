#include <bits/stdc++.h>

using namespace std;

int arr[11];
int dp[11][10001];
bitset<10001> visited[11];

int solve(int n, int m) {
    if (m == 0 && n == 0) return 0;
    if (m < 0 || n == 0) return 1e9;
    if (visited[n][m]) return dp[n][m];

    int ans = solve(n-1, m - arr[n]*arr[n]);
    for (int i = 1; ; i++) {
        if (i*i > m) break;
        ans = min(ans, solve(n-1, m - i*i) + abs(arr[n]-i)*abs(arr[n]-i));
    }

    visited[n][m] = true;
    return dp[n][m] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = solve(n, m);
    ans = ans == 1e9 ? -1 : ans;

    cout << ans << '\n';

    return 0;
}
