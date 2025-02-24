#include <bits/stdc++.h>

using namespace std;

int mem[501][501];
int v[501];
int w[501];
vector<int> vec;

void solve(int n, int m) {
    if (n == 0 || m == 0) return ;
    if (mem[n][m] == mem[n-1][m]) {
        return solve(n-1, m);
    }
    if (m >= w[n] && mem[n-1][m] <= mem[n][m - w[n]] + v[n]) {
        vec.push_back(n);
        return solve(n-1, m - w[n]);
    } else {
        return solve(n-1, m);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> mem[i][j];
        }
    }

    solve(n, m);

    cout << vec.size() << '\n';
    for (int x: vec) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
