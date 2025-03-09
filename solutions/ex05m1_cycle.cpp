#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001);

int dfs(int u, int p) {
    if (visited[u]) return true;
    visited[u] = true;
    bool ans = false;
    for (int v: adj[u]) {
        if (v != p) {
            ans |= dfs(v, u);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        visited = vector<bool>(V + 1, false);
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
        }

        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;

            u++, v++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ans = false;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                ans |= dfs(i, -1);
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
