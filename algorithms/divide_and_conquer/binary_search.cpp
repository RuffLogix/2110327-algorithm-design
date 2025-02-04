#include <bits/stdc++.h>

using namespace std;

void create_random_vector(vector<int> &v) {
    for (int i=0; i<100; i++) {
        v.push_back(rand() % 1000 + 1);
    }
}

void print_vector(vector<int> &v) {
    for (int x: v) {
        cout << x << ' ';
    }
}

bool binary_search_vector(int l, int r, int x, vector<int> &v) {
    if (l == r) return v[l] == x;
    int m = (l + r) >> 1;
    return (v[m]<=x) 
		    ? binary_search_vector(l, m, x, v) 
		    : binary_search_vector(m+1, r, x, v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    srand(time(NULL));

    vector<int> v;
    create_random_vector(v);
    sort(v.begin(), v.end());
    print_vector(v);
    binary_search_vector(0, v.size()-1, 2, v);
    
    return 0;
}