#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
vector<bool> visited(10001, false);

void dfs(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            dfs(i);
            ans += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
