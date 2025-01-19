#include <bits/stdc++.h>

using namespace std;

vector<int> v(100001);
long long ans = 0;

void merge_array(int l, int r) {
    int m = (l + r) >> 1;

    vector<int> v1; v1.assign(v.begin()+l, v.begin()+m+1);
    vector<int> v2; v2.assign(v.begin()+m+1, v.begin()+r+1);

    int i=0, j=0, index=l;
    while (i != v1.size() || j != v2.size()) {
        if (i != v1.size() && j != v2.size()) {
            if (v1[i] <= v2[j]) {
                v[index] = v1[i];
                index++, i++;
            } else {
                v[index] = v2[j];
                index++, j++;
                ans += (v1.size() - i);
            }
        } else {
            if (i != v1.size()) {
                v[index] = v1[i];
                index++, i++;
            } else {
                v[index] = v2[j];
                index++, j++;
            }
        }
    }
}

void solve(int l, int r) {
    if (l == r) return ;
    int m = (l + r) >> 1;
    solve(l, m);
    solve(m+1, r);
    merge_array(l, r);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }

    solve(1, n);
    
    cout << ans << '\n';

    return 0;
}