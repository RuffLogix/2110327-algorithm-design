#include <bits/stdc++.h>

using namespace std;

int arr[300001];

vector<int> solve(int l, int r, int n) {
    if (n == 0) {
        vector<int> ans = {arr[l]};
        return ans;
    } else {
        int m = (l + r) >> 1;
        vector<int> rl = solve(l, m, n-1);
        vector<int> rr = solve(m+1, r, n-1);

        vector<int> ans;
        for (int i = 0; i<rl.size(); i++) 
            ans.push_back(rl[i] + rr[i]);

        for (int i = 0; i<rl.size(); i++) 
            ans.push_back(rl[i] - rr[i]);

        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = solve(1, n, log2(n));

    for (int x: ans) {
        cout << x << ' ';
    }   

    return 0;
}