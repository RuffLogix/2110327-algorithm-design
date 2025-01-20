#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> intervals;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        intervals.push_back({a, b});
    }    

    sort(intervals.begin(), intervals.end());

    vector<int> ans;
    for (pair<int, int> interval: intervals) {
        if (ans.empty() || ans.back() + 1 < interval.first ) {
            ans.push_back(interval.first);
            ans.push_back(interval.second);
        } else if (interval.first <= ans.back() + 1) {
            if (ans.back() + 1 <= interval.second) {
                ans.pop_back();
                ans.push_back(interval.second);
            }
        }
    }
    
    for (int x: ans) {
        cout << x << ' ';
    }

    return 0;
}