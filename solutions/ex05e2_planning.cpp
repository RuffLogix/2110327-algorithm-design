#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
int indeg[1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;

        while (m--) {
            int x;
            cin >> x;
            adj[x+1].push_back(i);
            indeg[i] += 1;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u-1 << ' ';
        for (int v: adj[u]) {
            indeg[v] -= 1;
            if (indeg[v] == 0) q.push(v);
        }
    }

    cout << '\n';

    return 0;
}
