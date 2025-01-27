#include <bits/stdc++.h>

using namespace std;

pair<int, int> monsters[11];
int t[11];

bool valid_index(int monster_index, int tower_index, int m, int k) {
    return tower_index <= k && monster_index <= m;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    for (int i = 1; i <= m; i++) cin >> monsters[i].first;
    for (int i = 1; i <= m; i++) cin >> monsters[i].second;
    for (int i = 1; i <= k; i++) cin >> t[i];

    sort(monsters+1, monsters+1+m);
    sort(t+1, t+1+k);

    int monster_index = 1, tower_index = 1;
    while (monster_index <= m && tower_index <= k) {
        if (valid_index(monster_index, tower_index, m, k) && monsters[monster_index].second == 0) monster_index++;
        if (valid_index(monster_index, tower_index, m, k) && monsters[monster_index].first < t[tower_index] - w) monster_index++;
        if (valid_index(monster_index, tower_index, m, k) && monsters[monster_index].first > t[tower_index] + w) tower_index++;

        if (valid_index(monster_index, tower_index, m, k) && abs(monsters[monster_index].first - t[tower_index]) <= w) {
            tower_index++; monsters[monster_index].second--;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += monsters[i].second;
    }

    cout << ans << '\n';

    return 0;
}