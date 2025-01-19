#include <bits/stdc++.h>

using namespace std;

void solve(int index, int n, int cnt, int k, bool found, string s) {
    if (index == n) {
        if (found || cnt >= k) {
            cout << s << '\n';
        }

        return ;
    }

    solve(index+1, n, 0, k, found, s + "0");
    solve(index+1, n, cnt+1, k, found || (cnt+1 == k), s + "1");
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    solve(0, n, 0, k, false, "");

    return 0;
}