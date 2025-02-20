#include <bits/stdc++.h>

using namespace std;

bitset<501> visited[501];
int dp[501][501];

int solve(int n, int m, string &s1, string &s2) {
    if (n == 0 || m == 0) return 0;
    if (visited[n][m]) return dp[n][m];

    int ans = s1[n-1] == s2[m-1] ? solve(n-1, m-1, s1, s2) + 1 
                                 : max(solve(n-1, m, s1, s2), solve(n, m-1, s1, s2));
    visited[n][m] = true;
    
    return dp[n][m] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    cout << solve(s1.size(), s2.size(), s1, s2);

    return 0;
}