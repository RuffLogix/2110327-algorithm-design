#include <bits/stdc++.h>

using namespace std;

const int V = 10001;
vector<int> adj[V];
vector<bool> visited(V, false);
vector<int> dist(V, 1e9);
int virus[V];
int c[V];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++) {
        cin >> virus[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i-1];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 1; i <= k; i++) {
        pq.push({c[virus[i]], virus[i]});
        dist[virus[i]] = c[virus[i]];
        visited[virus[i]] = true;
    }

    int ans = 0;
    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        ans = max(ans, d);
        visited[u] = true;
        for (int v: adj[u]) {
            if (!visited[v] && dist[v] > dist[u] + c[v]) {
                dist[v] = dist[u] + c[v];
                pq.push({dist[v], v});
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
