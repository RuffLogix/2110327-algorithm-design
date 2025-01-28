#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    int ans = -1e9;
    int cur_sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x;

        if (cur_sum + x < x) {
            cur_sum = x;
        } else {
            cur_sum += x;
        }
        ans = max(ans, cur_sum);
    }

    cout << ans << '\n';

    return 0;
}