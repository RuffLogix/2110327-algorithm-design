#include <bits/stdc++.h>

using namespace std;

int fw[200001];
map<int, int> mp;

void update(int index) {
    for (; index <= 200000; index += index&-index) {
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        mp[x] = query(200000) - query(x);
        update(x);
    }

    while (t--) {
        int x;
        cin >> x;

        cout << mp[x] << '\n';
    }

    return 0;
}