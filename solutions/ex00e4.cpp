#include <bits/stdc++.h>

using namespace std;

void solve(int ca, int cb, int a, int b, string s) {
    if (ca + cb == b) {
        if (ca != a) return ;
        cout << s << '\n';

        return ;
    } 

    solve(ca, cb+1, a, b, s + "0");
    solve(ca+1, cb, a, b, s + "1");
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int a, b;
    cin >> a >> b;

    solve(0, 0, a, b, "");

    return 0;
}