#include <bits/stdc++.h>

using namespace std;

int qs[500001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);    

    int n,m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] += qs[i-1];        
    }

    while (m--) {
        long long a, b;
        cin >> a >> b;
        a += 1;

        int ans = 0;
        int l = a, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;

            int grass = qs[mid] - qs[a-1];
            long long cost = grass + (mid - a + 1LL) * k; 
            if (cost <= b) {
                ans = grass;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}