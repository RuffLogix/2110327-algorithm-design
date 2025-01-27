#include <bits/stdc++.h>

using namespace std;

bool selected[21];
vector<int> available_days[21];
int nisit[1001];

int solve(int index, int m, int n, int cnt) {
    if (index > m) {
        for (int i = 1; i <= n; i++) {
            if (nisit[i] == 0) return 1e9;    
        }
        return cnt;
    } else {
        selected[index] = false;
        int r1 = solve(index+1, m, n, cnt);
        selected[index] = true;
        for (int day: available_days[index]) nisit[day]++;
        int r2 = solve(index+1, m, n, cnt+1);
        for (int day: available_days[index]) nisit[day]--;
        return min(r1, r2);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int n_available_days;
        cin >> n_available_days;

        while (n_available_days--) {
            int x;
            cin >> x;
            available_days[i].push_back(x);
        }
    }

    cout << solve(1, m, n, 0) << '\n';

    return 0;
}