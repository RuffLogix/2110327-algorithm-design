#include <bits/stdc++.h>

using namespace std;

int qs[300001];
set<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);    

    int n;
    cin >> n;

    int ans = -2e9;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        qs[i] = qs[i - 1] + x;

        auto result = s.lower_bound({x, -2e9});
        if (result != s.end() && (*result).first == x) {
            ans = max(ans, qs[i] - (*result).second);
        }

        s.insert({x, qs[i-1]});
        ans = max(ans, x);
    }

    cout << ans << '\n';

    return 0;
}