#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > adj[5001];
vector<int> dist(5001, 1e9);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int des;
    cin >> des;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        pq.push({0, u+1});
        dist[u+1] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;

        adj[u].push_back({v, w});
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (pair<int, int> v: adj[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    cout << dist[des + 1] << '\n';

    return 0;
}
