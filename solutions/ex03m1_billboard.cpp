#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int dp[10001];

int solve(int n) {
    if (n <= 0) return 0;
    if (dp[n]) return dp[n];
    return dp[n] = max(solve(n-1), solve(n-2) + arr[n]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << solve(n) << '\n';

    return 0;
}
