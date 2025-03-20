#include <bits/stdc++.h>

using namespace std;

pair<int, int> items[100001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    float W;
    int n;
    cin >> W >> n;

    for (int i = 1; i <= n; i++) cin >> items[i].first;
    for (int i = 1; i <= n; i++) cin >> items[i].second;

    sort(items+1, items+1+n, [](pair<int, int> a, pair<int, int> b) {
        return (float)b.second/b.first > (float)a.second/a.first;
    });

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        if (items[i].second <= W) {
            ans += items[i].first;
            W -= items[i].second;
        } else {
            ans += W * (float)items[i].first/items[i].second;
            W = 0;
            break;
        }
    }
    cout << fixed << setprecision(4) << ans << '\n';

    return 0;
}
