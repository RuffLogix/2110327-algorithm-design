#include <bits/stdc++.h>

using namespace std;

int items[101];
map<int, bool> dp[101][101];
int ans = 1e9;
int k;

void solve(int index, int n, int m, int sum) {
    if ((abs(k - sum) > ans && sum - k > 0) || m < 0 || dp[index][m][sum]) return;

    if (m == 0) ans = min(ans, abs(k - sum));

    if (index > n) {
        return ;
    }

    dp[index][m][sum] = 1;

    solve(index + 1, n, m, sum);
    solve(index + 1, n, m - 1, sum + items[index]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    solve(1, n, m, 0);

    cout << ans << '\n';

    return 0;
}
