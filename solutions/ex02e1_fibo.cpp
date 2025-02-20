#include <bits/stdc++.h>

using namespace std;

int dp[51];

int solve(int n) {
	if (n == 0 || n == 1) return n;
	if (dp[n]) return dp[n];
	
	return dp[n] = solve(n-1) + solve(n-2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;

	cout << solve(n) << '\n';

    return 0;
}