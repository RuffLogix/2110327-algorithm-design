#include <bits/stdc++.h>

using namespace std;

bool arr[1001];

bool solve(int l, int r) {
    int m = (l + r) >> 1;
    if (m == (r < l ? r : l)) return (r < l) == arr[m];
    return (solve(l, m) || solve(m, l)) && solve(m, r);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        bool valid = true;
        for (int j = 1; j <= 1 << (k-1); j++) {
            bool a, b;
            cin >> a >> b;
            valid &= a^b;
            arr[j] = a;
        }

        cout << ((valid && solve(1, (1 << (k-1)) + 1)) ? "yes" : "no") << '\n';
    }   

    return 0;
}