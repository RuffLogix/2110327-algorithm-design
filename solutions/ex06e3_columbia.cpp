#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > mp;
vector<vector<int> > dist;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    mp = vector<vector<int> >(n + 1, vector<int>(m + 1));
    dist = vector<vector<int> >(n + 1, vector<int>(m + 1, 1e9));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    dist[1][1] = 0;
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push({0, {1, 1}});

    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            if (valid(x+dx[i], y+dy[i]) && dist[x+dx[i]][y+dy[i]] > dist[x][y] + mp[x+dx[i]][y+dy[i]]) {
                dist[x+dx[i]][y+dy[i]] = dist[x][y] + mp[x+dx[i]][y+dy[i]];
                pq.push({dist[x+dx[i]][y+dy[i]], {x+dx[i], y+dy[i]}});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
