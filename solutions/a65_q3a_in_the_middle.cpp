#include <bits/stdc++.h>

using namespace std;

vector<int> adj[250001];
int dist[4][250001];
int t[4];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= 3; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }

        for (int j = 1; j <= 3; j++) {
            dist[j][i] = 1e9;
        }
    }

    for (int i = 1; i <= 3; i++) {
        queue<int> q;
        q.push(t[i]);
        dist[i][t[i]] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: adj[u]) {
                if (dist[i][v] > dist[i][u] + 1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(dist[1][i], max(dist[2][i], dist[3][i])));
    }
    cout << ans << '\n';

    return 0;
}
