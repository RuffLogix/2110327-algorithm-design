#include <bits/stdc++.h>

using namespace std;

struct Item {
    double w, v;

    Item() { }
    Item(double w, double v): w(w), v(v) { }
};

Item items[101];
map<double, double> dp[101];
double real_ans = -1e9;

double rational_knapsack(int index, int n, double W) {
    double ans = 0;
    vector<Item> item_vector;

    for (int i = index; i <= n; i++) item_vector.push_back(items[i]);
    sort(item_vector.begin(), item_vector.end(), [&](Item a, Item b) {
        return a.v/a.w > b.v/b.w;
    });

    for (Item item: item_vector) {
        if (W > item.w) {
            ans += item.v;
            W -= item.w;
        } else {
            ans += item.v/item.w * W;
            W = 0;
            break;
        }
    }

    return ans;
}

double solve(int index, int n, double sum, double W) {
    if (W < 0) return -1e9;
    if (index > n || rational_knapsack(index, n, W) + sum <= real_ans) return sum;
    if (dp[index][W]) return dp[index][W];

    return real_ans = max(real_ans, dp[index][W] = max(solve(index + 1, n, sum + items[index].v, W - items[index].w), solve(index + 1, n, sum, W)));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    double W;
    int n;

    cin >> W >> n;

    for (int i = 1; i <= n; i++) cin >> items[i].v;
    for (int i = 1; i <= n; i++) cin >> items[i].w;

    cout << fixed << setprecision(4) << solve(1, n, 0, W) << '\n';

    return 0;
}
