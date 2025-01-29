#include <bits/stdc++.h>

using namespace std;

int chef[1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> chef[i];
    }

    while (m--) {
        long long x;
        cin >> x;

        long long l = 0, r = 1e12;
        long long ans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;

            long long cnt = n;
            for (int i = 1; i <= n; i++) {
                cnt += (mid) / chef[i];
            }

            if (cnt >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}