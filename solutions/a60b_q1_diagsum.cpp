#include <bits/stdc++.h>

using namespace std;

int arr[2001][1001];
int indices[2001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int row = i-j+1000;
            cin >> arr[row][++indices[row]];
            arr[row][indices[row]] += arr[row][indices[row] - 1];
        }
    }

    int ans = -1e9;
    for (int i = 0; i <= 2001; i++) {
        for (int j = 1; j <= indices[i]; j++) {
            for (int k = 1; k <= j; k++) {
                ans = max(ans, arr[i][j] - arr[i][k-1]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
