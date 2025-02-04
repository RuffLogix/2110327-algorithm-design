#include <bits/stdc++.h>

using namespace std;

pair<int, int> points[50001];

long long get_distance(pair<int, int> a, pair<int, int> b) {
    long long dx = (a.first - b.first);
    long long dy = (a.second - b.second);
    return dx*dx + dy*dy;
}

long long find_closest_distance(int l, int r) {
    if (l == r) return 1e18;
    int m = (l + r) >> 1;
    long long ans = min(find_closest_distance(l, m), find_closest_distance(m+1, r));

    for (int i = max(l, m-8); i <= m; i++) {
        for (int j = m + 1; j <= min(r, m+8); j++) { 
            ans = min(ans, get_distance(points[i], points[j]));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);    

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points+1, points+1+n);

    cout << find_closest_distance(1, n) << '\n';

    return 0;
}