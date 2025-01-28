#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }    

    sort(arr+1, arr+1+n);

    while (t--) {
        int x;
        cin >> x;

        int ans = upper_bound(arr+1, arr+1+n, x) - arr - 1;
        cout << (ans ? ans - 1 : -1) << '\n';
    }

    return 0;
}