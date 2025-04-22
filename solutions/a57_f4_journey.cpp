#include <bits/stdc++.h>

using namespace std;

struct State {
    int u, d, p;
    State(int u, int d, int p) : u(u), d(d), p(p) {}

    bool operator<(const State &other) const {
        return d < other.d;
    }
};

vector<pair<int, int> > adj[21];
int dp[21][1 << 20];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 21; i++)
        for (int j = 0; j < (1 << 20); j++)
            dp[i][j] = -1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (i != j && (w > 0 || n <= 18)) adj[i].push_back({j, w});
        }
    }

    priority_queue<State> pq;
    dp[0][1] = 0;
    pq.push(State(0, 0, 1));

    while (!pq.empty()) {
        int u = pq.top().u, d = pq.top().d, p = pq.top().p;
        pq.pop();
        if (dp[u][p] > d) continue;
        if (u == n-1 && p != (1<<n) - 1) continue;
        // if (u == n-1 && p == (1 << n) - 1) break;

        for (auto v : adj[u]) {
            int next_city = v.first, happiness = v.second;

            if (!(p & (1 << next_city))) {
                int next_mask = p | (1 << next_city);
                if (dp[next_city][next_mask] >= d + happiness) continue;
                dp[next_city][next_mask] = d + happiness;
                pq.push(State(next_city, dp[next_city][next_mask], next_mask));
            }
        }
    }

    cout << dp[n-1][(1 << n) - 1] << '\n';
    return 0;
}
