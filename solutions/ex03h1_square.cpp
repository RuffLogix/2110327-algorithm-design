#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j-1] - '0';
            arr[i][j] = arr[i][j] ? min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1])) + 1 : 0;
            ans = max(ans, arr[i][j]);
        }
    }    
    cout << ans << '\n';

    return 0;
}