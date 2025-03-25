#include <bits/stdc++.h>

using namespace std;

vector<int> adj[2001];
vector<int> mx(2001, -1e9);
vector<bool> visited(2001, false);
int c[2001];

void solve(int u) {
    visited[u] = true;
    mx[u] = max(mx[u], c[u]);

    for (int v: adj[u]) {
        if (!visited[v]) {
            solve(v);
        }
        mx[u] = max(mx[u], mx[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= V; i++) cin >> c[i];
    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= V; i++) {
        solve(i);
    }

    int ans = -1e9;
    for (int i = 1; i <= V; i++) {
        ans = max(ans, mx[i] - c[i]);
    }
    cout << ans << '\n';

    return 0;
}
