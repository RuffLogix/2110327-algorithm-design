#include <bits/stdc++.h>

using namespace std;

int arr[5001];
int dp[5001][5001];

int solve(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r]) return dp[l][r];
    int r1 = solve(l+1, r-1) + max(arr[l], arr[r]);
    int r2 = solve(l+2, r) + max(arr[l], arr[l+1]);
    int r3 = solve(l, r-2) + max(arr[r], arr[r-1]);
    return dp[l][r] = max(r1, max(r2, r3));
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
