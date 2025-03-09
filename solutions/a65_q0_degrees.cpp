#include <bits/stdc++.h>

using namespace std;

bool adj[5001][5001];
int deg[5001];
int cnt[5001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            deg[i] += adj[i][j];
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cnt[deg[i]] += 1;
        mx = max(mx, deg[i]);
    }

    for (int i = 0; i <= mx; i++) {
        cout << cnt[i] << ' ';
    }

    cout << '\n';

    return 0;
}
