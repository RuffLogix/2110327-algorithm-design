#include <bits/stdc++.h>

using namespace std;

char perm[13];
set<string> perms;

void solve(int index, int n, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return ;
    if (index == 0) { 
        string s;
        for (int i=1; i<=n; i++) {
            s += perm[i];
        }
        perms.insert(s);
        return ;
    }

    perm[index] = 'A';
    solve(index-1, n, a-1, b, c);
    perm[index] = 'B';
    solve(index-1, n, a, b-1, c);
    perm[index] = 'C';
    solve(index-1, n, a, b, c-1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    solve(n, n, a, b, c);
    cout << perms.size() << '\n';

    for (string s: perms) {
        cout << s << '\n';
    }

    return 0;
}