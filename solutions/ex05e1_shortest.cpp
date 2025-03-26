#include <bits/stdc++.h>

using namespace std;

int n, m;
string mp[101];
int dist[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (mp[x][y] == '#') return false;
    return true;
}

void solve(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (valid(x+dx[i], y+dy[i]) && dist[x+dx[i]][y+dy[i]] > dist[x][y] + 1) {
            dist[x+dx[i]][y+dy[i]] = dist[x][y] + 1;
            solve(x+dx[i], y+dy[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            dist[i][j] = 1e9;
        }
    }

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }

    dist[0][0] = 0;
    solve(0, 0);

    cout << (dist[n-1][m-1] == 1e9 ? -1 : dist[n-1][m-1]) << '\n';

    return 0;
}
