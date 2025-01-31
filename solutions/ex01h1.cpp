#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void generate_table() { 
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);     
    v.push_back(5);

    for (int i = 3; v.back() <= 2e9; i++) {
        int n = v[i] - v[i-1];
        while (n--) {
            v.push_back(i);
            v[v.size()-1] += v[v.size()-2];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);    

    generate_table();

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        cout << (lower_bound(v.begin(), v.end(), x) - v.begin()) << '\n';
    }    

    return 0;
}