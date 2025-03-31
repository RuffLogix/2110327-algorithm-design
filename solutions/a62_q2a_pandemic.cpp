#include <bits/stdc++.h>

using namespace std;

vector<vector<int > > dist(501, vector<int>(501, 1e9));
int mp[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y, int r, int c) {
    if (x < 1 || y < 1 || x > r || y > c) return false;
    if (mp[x][y] == 2) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int r, c, t;
    cin >> r >> c >> t;

    queue<pair<int, int> > q;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (valid(x+dx[i], y+dy[i], r, c) && dist[x+dx[i]][y+dy[i]] > dist[x][y] + 1) {
                dist[x+dx[i]][y+dy[i]] = dist[x][y] + 1;
                q.push({x+dx[i], y+dy[i]});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (dist[i][j] <= t) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
