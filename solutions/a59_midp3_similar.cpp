#include <bits/stdc++.h>

using namespace std;

bool solve(string a, string b) {
    if (a == b) {
        return true;
    } else {
        if (a.size() == 1 || a.size() != b.size()) return false;
        bool c1 = solve(a.substr(0, a.size()/2), b.substr(0, b.size()/2)) && solve(a.substr(a.size()/2, a.size()/2), b.substr(b.size()/2, b.size()/2));
        bool c2 = solve(a.substr(0, a.size()/2), b.substr(b.size()/2, b.size()/2)) && solve(a.substr(a.size()/2, a.size()/2), b.substr(0, b.size()/2));

        return c1 || c2;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);    

    string a, b;
    cin >> a >> b;

    cout << (solve(a, b) ? "YES" : "NO") << '\n';

    return 0;
}