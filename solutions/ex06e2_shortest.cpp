#include <bits/stdc++.h>

using namespace std;

int adj[101][101];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 1e9;
        }
        adj[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        adj[u][v] = w;
    }

    bool found_cycle = false;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                found_cycle |= (i == j && adj[i][j] != 0);
            }
        }
    }

    if (found_cycle) {
        cout << -1 << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            cout << adj[s+1][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
