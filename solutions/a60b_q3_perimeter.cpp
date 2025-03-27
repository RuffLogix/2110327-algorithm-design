#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
vector<int> dist(1001, 1e9);

void solve(int u) {
    for (int v: adj[u]) {
        if (dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
            solve(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, e, k;
    cin >> n >> e >> k;

    for (int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[0] = 0;
    solve(0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dist[i] == k;
    }
    cout << ans << '\n';

    return 0;
}
