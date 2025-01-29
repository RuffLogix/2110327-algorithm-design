#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> ans;

void solve(int l, int r) {
    if (l == r) {
        ans.push_back(l);
    } else if (k == 0) {
        for (int i = l; i <= r; i++) {
            ans.push_back(i);
        }
    } else {
        if (k < 0) return ;

        int m = (l + r) >> 1;

        k -= 2;
        solve(m+1, r);
        solve(l, m);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> k;

    k -= 1;
    solve(1, n);    

    if (k < 0) {
        cout << -1 << '\n';
    } else {
        for (int x: ans) {
            cout << x << ' ';
        }
    }

    return 0;
}