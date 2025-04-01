#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > dist(1001, vector<int>(1001, 1e9));
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y, int r, int c) {
    if (x < 1 || y < 1 || x > r || y > c) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int r, c, k;
    cin >> r >> c >> k;

    queue<pair<int, int> > q;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int x;
            cin >> x;
            if (x) {
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
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny, r, c) && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int c = dist[i][j];
            cout << (c == 0 ? 1 : c <= k ? 2 : 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
