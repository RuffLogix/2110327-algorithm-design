#include <bits/stdc++.h>

using namespace std;

int d[200001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i-1];
    }

    while (k--) {
        int p, w;
        cin >> p >> w;

        int l = p, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l+r) >> 1;

            if (d[mid] - d[p-1] - (mid - p + 1)*m >= w) {
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
