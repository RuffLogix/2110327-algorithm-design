#include <bits/stdc++.h>

using namespace std;

int fw[100001];
pair<int, int> points[100001];

void update(int index) {
    for (; index <= 100000; index += index&-index) {
        fw[index] += 1;
    }
}

int query(int index) {
    int ans = 0;
    for (; index > 0; index -= index&-index) {
        ans += fw[index];
    } 
    return ans;
}

vector<int> coord;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
        coord.push_back(points[i].second);
    }

    coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
    sort(coord.begin(), coord.end());

    for (int i = 1; i <= n; i++) {
        points[i].second = lower_bound(coord.begin(), coord.end(), points[i].second) - coord.begin() + 1;        
    }

    sort(points+1, points+1+n, greater<pair<int, int>>());

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pair<int, int> point = points[i];
        if (query(100000) - query(point.second) == 0) {
            ans += 1;
        }
        update(point.second);
    }

    cout << ans << '\n';

    return 0;
}