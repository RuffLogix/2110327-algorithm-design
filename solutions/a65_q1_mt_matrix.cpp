#include <bits/stdc++.h>

using namespace std;

int arr[3][3];

int solve(long long x, long long y, int n, int flag = 1) {
    if (n == 1) {        
        return arr[x][y] * flag;
    }

    long long m = 1LL << (n-1);
    if (x <= m && y <= m) {
        return solve(x, y, n-1, flag);
    } else if (x <= m && y > m) {
        return solve(y-m, x, n-1, flag);
    } else if (x > m && y <= m) {
        return solve(x-m, y, n-1, flag*-1);
    } else {
        return solve(y-m, x-m, n-1, flag*-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            cin >> arr[i][j];
        }
    }

    while (t--) {
        long long x, y;
        cin >> x >> y;

        cout << solve(x, y, n) << '\n';
    }

    return 0;
}