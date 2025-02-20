#include <bits/stdc++.h>

using namespace std;

int dp[31][31];

int solve(int n, int k) {
	if (n < k) return 0;
	if (k == 0 || n == k) return 1;	
	if (dp[n][k]) return dp[n][k];

	return dp[n][k] = solve(n-1, k-1) + solve(n-1, k);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
	cin >> n >> k;

	cout << solve(n, k) << '\n';

    return 0;
}