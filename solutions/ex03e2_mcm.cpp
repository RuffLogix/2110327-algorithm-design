#include <bits/stdc++.h>

using namespace std;

int arr[101];
int dp[101][101];

int solve(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r]) return dp[l][r];

    int ans = 1e9;
    for (int i = l; i < r; i++) {
        ans = min(ans, solve(l, i) + solve(i+1, r) + arr[l]*arr[i+1]*arr[r+1]);
    }

    return dp[l][r] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n+1; i++) {
        cin >> arr[i];
    }

    cout << solve(1, n) << '\n';

    return 0;
}