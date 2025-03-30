#include <bits/stdc++.h>

using namespace std;

int b[5001];
int wildfire[5001];
vector<int> adj[5001];

int dfs(int u) {
  int ans = b[u];
  b[u] = 0;
  for (int v: adj[u]) {
    if (b[v]) {
      ans += dfs(v);
    }
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      sum += b[i];
    }

    for (int i = 1; i <= k; i++) {
      cin >> wildfire[i];
      wildfire[i]++;
    }

    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u+1].push_back(v+1);
    }

    for (int i = 1; i <= k; i++) {
      if (b[wildfire[i]] != 0) {
        sum -= dfs(wildfire[i]);
      }
      cout << sum << ' ';
    }

    return 0;
}
