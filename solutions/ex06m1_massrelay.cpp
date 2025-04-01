#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int> > > edges;
int par[5001];

int f(int u) {
    if (par[u] == u || par[u] == 0) return u;
    return par[u] = f(par[u]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    vector<int> mst;
    for (pair<int, pair<int, int> > edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;

        u = f(u), v = f(v);

        if (u != v) {
            par[u] = v;
            mst.push_back(edge.first);
        }
    }

    sort(mst.begin(), mst.end(), greater<int>());

    while (q--) {
        int k;
        cin >> k;

        cout << mst[k - 1] << '\n';
    }

    return 0;
}
