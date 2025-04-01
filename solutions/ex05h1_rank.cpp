#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5001];
vector<int> radj[5001];
set<int> dadj[5001];
vector<vector<int> > groups;
vector<bool> visited(5001, false);
stack<int> st;
int indeg[5001];
int dist[5001];
int ans[5001];
int gsize[5001];
int head[5001];
int mx = 0;

void dfs(int u) {
    for (int v: dadj[u]) {
        if (dist[v] < dist[u] + 1) {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

void dfs1(int u) {
    visited[u] = true;
    for (int v: radj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<int> &group) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs2(v, group);
        }
    }
    group.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    visited = vector<bool>(5001, false);
    while (!st.empty()) {
        int u = st.top(); st.pop();

        if (!visited[u]) {
            vector<int> group;
            dfs2(u, group);
            groups.push_back(group);
        }
    }

    visited = vector<bool>(5001, false);
    set<int> rep;
    for (vector<int> g: groups) {
        int index = -1;
        for (int m: g) {
            if (index == -1) index = m;
            gsize[index] += 1;
            visited[m] = true;
        }
        rep.insert(index);

        for (int m: g) {
            head[m] = index;
            visited[m] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int v: adj[i]) {
            if (head[i] == head[v]) continue;
            dadj[head[i]].insert(head[v]);
            indeg[head[v]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0 && rep.find(i) != rep.end()) {
            dist[i] = 0;
            dfs(i);
        }
    }

    for (int v: rep) {
        ans[dist[v]] += gsize[v];
        mx = max(mx, dist[v]);
    }

    for (int i = 0; i <= mx; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
