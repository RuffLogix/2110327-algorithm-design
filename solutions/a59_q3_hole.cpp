#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int mp[N][N];
vector<vector<int> > d(N, vector<int>(N, 1e9));
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y, int n) {
    if (x < 1 || y < 1 || x > n || y > n) return false;
    return true;
}

bool is_edge(int x, int y) {
    if (x == 1 || y == 1 || x == 1000 || y == 1000) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }

    queue<pair<int, int> > q;
    q.push({a, b});

    d[a][b] = 0;
    int ans = 1e9;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (is_edge(x, y)) {
            ans = min(ans, d[x][y]);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            if (valid(x+dx[i], y+dy[i], N - 1) && d[x+dx[i]][y+dy[i]] > d[x][y] + mp[x+dx[i]][y+dy[i]]) {
                d[x+dx[i]][y+dy[i]] = d[x][y] + mp[x+dx[i]][y+dy[i]];
                q.push({x+dx[i], y+dy[i]});
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
