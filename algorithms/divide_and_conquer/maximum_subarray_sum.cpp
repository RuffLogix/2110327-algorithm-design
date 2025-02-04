#include <bits/stdc++.h>

using namespace std;

int qs[1001];

int query(int l, int r) {
    return qs[r] - qs[l-1];
}

int maximum_subarray_sum(int l, int r, int arr[]) {
    if (l == r) return arr[l];
    int m = (l + r) >> 1;

    int r1 = maximum_subarray_sum(l, m, arr);
    int r2 = maximum_subarray_sum(m+1, r, arr);

    int mx1 = INT_MIN;
    int mx2 = INT_MIN;
    for (int i=l; i<=m; i++) mx1 = max(mx1, query(i, m));
    for (int i=m+1; i<=r; i++) mx2 = max(mx2, query(m+1, i));

    return max(mx1+mx2, max(r1, r2));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int arr[] = {3, -4, 1, 2, -1, -1, 5, -4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=1; i<=n; i++) qs[i] = qs[i-1] + arr[i-1];

    cout << maximum_subarray_sum(0, n-1, arr) << '\n';

    return 0;
}