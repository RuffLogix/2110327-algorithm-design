#include <bits/stdc++.h>

using namespace std;

int queens[13];
bool check[13];

bool is_diagonal(int index, int queen) {
    for (int i = 1; i < index; i++) {
        if (abs(queens[i] - queen) == abs(i - index)) {
            return true;
        }
    }
    return false;
}

int solve(int index, int n) {
    if (index > n) {
        return 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[i] && !is_diagonal(index, i)) {
            check[i] = true;
            queens[index] = i;
            ans += solve(index + 1, n);
            check[i] = false;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    cout << solve(1, n) << '\n';

    return 0;
}
