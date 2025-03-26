#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<pair<int, int> > adj[1001];
vector<bool> visited(1001, false);
long long dist[1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w != -1 && w != 0) adj[i].push_back({j, w});
        }
        dist[i] = 1e9;
    }

    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int ,int> > > pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        visited[u] = true;
        pq.pop();
        for (pair<int, int> v: adj[u]) {
            if (!visited[v.first] && dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    long long ans = 0;
    bool cannot_reach = false;
    for (int i = 1; i <= n; i++) {
        cannot_reach |= (dist[i] == 1e9);
       ans = max(ans, dist[i]);
    }
    ans = cannot_reach ? -1 : ans;
    cout << ans << '\n';

    return 0;
}
