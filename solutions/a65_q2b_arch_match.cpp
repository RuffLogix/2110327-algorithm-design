#include <bits/stdc++.h>

using namespace std;

int arr[501];
int dp[501][501];
bitset<501> visited[501];

int solve(int l, int r) {
    if (l >= r) return 0;
    if (visited[l][r]) return dp[l][r];

    int ans = solve(l+1, r-1) + arr[l]*arr[r];
    for (int i = l; i < r; i++) {
        int r1 = max(solve(l, i), max(solve(l+1, i), solve(l, i-1)));
        int r2 = max(solve(i+1, r), max(solve(i+2, r), solve(i+1, r-1)));
        ans = max(ans, r1 + r2);
    }

    visited[l][r] = true;
    return dp[l][r] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << solve(1, n) << '\n';

    return 0;
}
