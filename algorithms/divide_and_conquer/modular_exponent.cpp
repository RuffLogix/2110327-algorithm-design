#include <bits/stdc++.h>

using namespace std;

int modular_exponent(int x, int n, int m = 1e9 + 7) {
    if (n == 0) return 1;
    if (n == 1) return x;

    int ans = modular_exponent(x, n/2) % m;
    return (n%2) ? (((ans*ans)%m)*x)%m : (ans*ans)%m;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int x, n;
    cin >> x >> n;

    cout << modular_exponent(x, n);

    return 0;
}