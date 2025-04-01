#include <bits/stdc++.h>

using namespace std;

int ci[2001], co[2001];
int dist[2001];
vector<int> adj[2001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> ci[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> co[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
    }

    memset(dist, 0x3f3f3f3f, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();

        for (int v: adj[u]) {
            if (dist[v] > dist[u] + co[u] + ci[v]) {
                dist[v] = dist[u] + co[u] + ci[v];
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == 0x3f3f3f3f ? -1 : dist[i]) << ' ';
    }

    return 0;
}
