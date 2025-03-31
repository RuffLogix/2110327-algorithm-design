#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
vector<int> dist(1001, 1e9);

void dfs(int u) {
    for (int v: adj[u]) {
        if (dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dist = vector<int>(1001, 1e9);
        dist[i] = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v: adj[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += (dist[j] && dist[j] <= k);
        }
        ans = max(ans, cnt);
    }
    cout << ans + 1<< '\n';

    return 0;
}
