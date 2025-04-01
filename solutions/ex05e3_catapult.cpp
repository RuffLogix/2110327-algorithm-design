#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
vector<int> radj[1001];
vector<bool> visited(1001, false);
stack<int> st;

void dfs1(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    st.push(u);
}

int dfs2(int u) {
    int ans = 1;
    visited[u] = true;
    for (int v: radj[u]) {
        if (!visited[v]) {
            ans += dfs2(v);
        }
    }
    return ans;
}

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
            x++;
            adj[i].push_back(x);
            radj[x].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    visited = vector<bool>(1001, false);

    multiset<int> mst;
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            mst.insert(dfs2(u));
        }
    }

    for (int x: mst) {
        cout << x << ' ';
    }

    return 0;
}
