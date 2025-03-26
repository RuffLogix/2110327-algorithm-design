#include <bits/stdc++.h>

using namespace std;

int adj[501][501];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            adj[i][j] = 1e9;
        }
        adj[i][i] = 0;
    }

    int V, E;
    cin >> V >> E;

    int u, v, e;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v >> e;
        u++, v++;
        adj[u][v] = e;
        adj[v][u] = e;
    }

    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            ans = max(ans, adj[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}
