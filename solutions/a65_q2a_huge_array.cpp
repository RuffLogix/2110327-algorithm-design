#include <bits/stdc++.h>

using namespace std;

int qs[100001];
int val[100001];
pair<int, int> arr[100001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr+1, arr+1+n);

    for (int i = 1; i <= n; i++) {
        qs[i] = qs[i-1] + arr[i].second;
        val[i] = arr[i].first;
    }

    while (q--) {
        int x;
        cin >> x;

        int index = lower_bound(qs+1, qs+1+n, x) - qs;

        cout << val[index] << '\n';
    }

    return 0;
}