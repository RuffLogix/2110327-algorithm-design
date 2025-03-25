#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
vector<bool> visited(100001, false);
vector<int> dist(100001, 0);

int ans = 0;

void dfs(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (visited[v]) {
            ans = max(ans, dist[v] - dist[u] + 1);
        } else {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    cout << ans << '\n';

    return 0;
}
