#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

string solve(int n, int m, string &s1, string &s2) {
    if (dp[n][m] == 0) return "";
    if (dp[n][m] == dp[n-1][m]) return solve(n-1, m, s1, s2);
    if (dp[n][m] == dp[n][m-1]) return solve(n, m-1, s1, s2);
    return solve(n-1, m-1, s1, s2) + s2[m-1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> dp[i][j];
        }
    }

    cout << solve(n, m, s1, s2) << '\n';

    return 0;
}