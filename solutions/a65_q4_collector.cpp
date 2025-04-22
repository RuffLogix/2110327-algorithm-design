#include <bits/stdc++.h>

using namespace std;

bool seller_books[81][1001];
bool sellers[81];
int available[1001];
pair<int, vector<int> > sellers_data[81];
int ans = 0;

void solve(int idx, int n, int price, int k) {
    while (idx <= n && available[idx] != 0) {
        idx += 1;
    }
    if (idx > n || price > ans) {
        ans = min(ans, price);
        return;
    }

    if (price >= ans) return;

    vector<int> seller_candidates;
    for (int i = 1; i <= k; i++) {
        if (seller_books[i][idx] && !sellers[i]) {
            seller_candidates.push_back(i);
        }
    }

    sort(seller_candidates.begin(), seller_candidates.end(), [&](int a, int b) {
        int cnt_a = 0, cnt_b = 0;
        for (int book : sellers_data[a].second) {
            if (available[book] == 0) cnt_a++;
        }
        for (int book : sellers_data[b].second) {
            if (available[book] == 0) cnt_b++;
        }
        double ra = (cnt_a == 0 ? 1e9 : (double)sellers_data[a].first / cnt_a);
        double rb = (cnt_b == 0 ? 1e9 : (double)sellers_data[b].first / cnt_b);
        return ra < rb;
    });

    int cnt = 3;
    for (int i : seller_candidates) {
        if (sellers_data[i].first )
        for (int book : sellers_data[i].second) available[book] += 1;
        sellers[i] = true;
        solve(idx + 1, n, price + sellers_data[i].first, k);
        sellers[i] = false;
        for (int book : sellers_data[i].second) available[book] -= 1;
        cnt -= 1;
        if (cnt == 0) break;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        int m;
        cin >> sellers_data[i].first >> m;

        ans += sellers_data[i].first;

        while (m--) {
            int x;
            cin >> x;
            seller_books[i][x] = true;
            sellers_data[i].second.push_back(x);
        }
    }

    solve(1, n, 0, k);
    cout << ans << '\n';

    return 0;
}
