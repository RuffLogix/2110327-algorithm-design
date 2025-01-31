#include <bits/stdc++.h>

using namespace std;

int arr[(1 << 8) + 1][(1 << 8) + 1];

void solve(int x1, int x2, int y1, int y2, int a, int b) {
    if (x1 == x2 && y1 == y2) arr[x1][y1] = b;
    else {
        int mx = (x1 + x2) >> 1;
        int my = (y1 + y2) >> 1;
        solve(x1, mx, y1, my, a-1, b);
        solve(x1, mx, my+1, y2, a-1, b-1);
        solve(mx+1, x2, y1, my, a-1, b+1);
        solve(mx+1, x2, my+1, y2, a-1, b);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int a, b;
    cin >> a >> b;

    solve(1, 1<<a, 1, 1<<a, a, b);

    for (int i = 1; i <= 1<<a; i++) {
        for (int j = 1; j <= 1<<a; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}