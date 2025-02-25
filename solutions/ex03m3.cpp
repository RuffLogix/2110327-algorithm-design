#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;

    priority_queue<pair<int, int> > pq;
    pq.push({0, 0});
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (!pq.empty() && pq.top().second < i-k-1) pq.pop();
        x += -pq.top().first;
        pq.push({-x, i+k});
    }

    while (!pq.empty() && pq.top().second < n) pq.pop();

    cout << -pq.top().first << '\n';

    return 0;
}
