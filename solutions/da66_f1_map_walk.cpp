#include <bits/stdc++.h>

using namespace std;

bool board[10][10];
bool visited[10][10];
int n, m;

bool is_valid(int i, int j) {
    if (i < 0 || j < 0 || i>=n || j>=m || visited[i][j] || board[i][j]) return false;
    return true;
}

void solve(int i, int j, string s) {
    if (i == n-1 && j == m-1) {
        cout << s << '\n';
        return ;
    }

    visited[i][j] = true;
    if (is_valid(i, j+1)) solve(i, j+1, s + "A");
    if (is_valid(i+1, j)) solve(i+1, j, s + "B");
    if (is_valid(i-1, j)) solve(i-1, j, s + "C");
    visited[i][j] = false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, 0, "");
    cout << "DONE\n";

    return 0;
}