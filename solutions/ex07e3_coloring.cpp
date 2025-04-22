#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int colors[51];
int ans = 1e9;
int V, E;

bool canColor(int u, int color) {
    for (int v: adj[u]) {
        if (colors[v] == color) return false;
    }
    return true;
}

void solve(int u, int mx) {
    if (u > V || mx >= ans) {
        ans = min(ans, mx);
        return;
    }

    for (int color = 1; color <= mx + 1; color++) {
        if (canColor(u, color)) {
            colors[u] = color;
            solve(u + 1, max(mx, color));
            colors[u] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    colors[1] = 1;
    solve(2, 1);

    cout << ans << '\n';

    return 0;
}
