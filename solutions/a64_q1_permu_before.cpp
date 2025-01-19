#include <bits/stdc++.h>

using namespace std;

bool choosed[21];
int is_available[21];
int mem[21];

bool check_available(int x) {
    return is_available[x] != -1 && !choosed[is_available[x]];
}

void solve(int index, int n) {
    if (index == n) {
        for (int i=0; i<n; i++) {
            cout << mem[i] << ' ';
        }
        cout << '\n';

        return ;
    } 

    for (int i=0; i<n; i++) {
        if (choosed[i] || check_available(i)) continue;
        mem[index] = i;
        choosed[i] = true;
        solve(index+1, n);
        choosed[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) is_available[i] = -1;

    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;

        is_available[b] = a;
    }

    solve(0, n);

    return 0;
}