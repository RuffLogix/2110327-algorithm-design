#include <bits/stdc++.h>

using namespace std;

int cost[2001];
int par[2001];
vector<pair<int, pair<int, int> > > adj;

int f(int u) {
    if (par[u] == 0 || par[u] == u) return par[u] = u;
    return par[u] = f(par[u]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        for (int j = 1; j < i; j++) {
          adj.push_back({cost[i] ^ cost[j], {i, j}});
        }
    }

    sort(adj.begin(), adj.end(), [](const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b){
        return a.first > b.first;
    });

    int n_edges = 0;
    int index = 0;
    long long ans = 0;
    while (n_edges != n-1) {
        int a = f(adj[index].second.first);
        int b = f(adj[index].second.second);

        if (a != b) {
            par[a] = b;
            n_edges += 1;
            ans += adj[index].first;
        }
        index += 1;
    }
    cout << ans << '\n';

    return 0;
}
