#include <bits/stdc++.h>

using namespace std;

struct state {
    int u, d, p;

    state() { }
    state(int u, int d, int p): u(u), d(d), p(p) { }
};

int k[9];
vector<pair<int, int> > adj[21];
map<int, bool> dist;
bool dp[21][20001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 8; i++) {
        cin >> k[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    queue<state> q;
    for (int j = 0; j < n; j++) {
        q.push(state(j, 0, 1 << j));
    }

    while (!q.empty()) {
        int u = q.front().u;
        int d = q.front().d;
        int p = q.front().p;
        q.pop();

        for (pair<int, int> v: adj[u]) {
            if (!dp[v.first][d + v.second] && ((1<<v.first) & p) == 0) {
                dp[v.first][d + v.second] = true;
                dist[d + v.second] = true;
                q.push(state(v.first, d + v.second, p | (1 << v.first)));
            }
        }
    }

    for (int i = 1; i <= 8; i++) {
        cout << (dist[k[i]] ? "YES" : "NO") << '\n';
    }

    return 0;
}
