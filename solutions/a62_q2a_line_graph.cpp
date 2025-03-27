#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
bool visited[100001];
int n_vertices = 0;
int n_edges = 0;

bool dfs(int u) {
    visited[u] = true;
    bool ans = adj[u].size() <= 2;
    n_vertices += 1;
    n_edges += adj[u].size();
    for (int v: adj[u]) {
        if (!visited[v]) {
            ans &= dfs(v);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            n_vertices = n_edges = 0;
            bool res = dfs(i);
            n_edges /= 2;
            ans += res & (n_edges + 1 == n_vertices);
        }
    }
    cout << ans << '\n';

    return 0;
}
