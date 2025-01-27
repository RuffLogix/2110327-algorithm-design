#include <bits/stdc++.h>

using namespace std;

int solve(int x, int n, int k) {
    if (n == 0) return 1;
    if (n == 1) return x % k;
    int ans = solve(x, n/2, k) % k; 
    return (n % 2) ? (((ans * ans) % k) * x) % k : (ans * ans) % k;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int x, n, k;
    cin >> x >> n >> k;

    cout << solve(x, n, k) << '\n';

    return 0;
}