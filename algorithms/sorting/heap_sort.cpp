#include <bits/stdc++.h>

using namespace std;

void create_random_vector(vector<int> &v) {
    for (int i=0; i<100; i++) {
        v.push_back(rand() % 1000 + 1);
    }
}

void fix_down(int index, vector<int> &v, int sz) {
    int temp = v[index];
    int node = 2*index+1;
    while (node < sz) {
        if (node+1 < sz && v[node+1] > v[node]) node += 1;
        if (v[node] <= temp) break;
        v[index] = v[node];
        index = node;
        node = 2*index+1;
    }
    v[index] = temp;
}

void build_heap(vector<int> &v) {
    int n = v.size();
    for (int i=n / 2; i>=0; i--) {
        fix_down(i, v, n);
    }
}

void heap_sort(vector<int> &v) {
    build_heap(v);

    int n = v.size();
    for (int i=n-1; i>=0; i--) {
        swap(v[0], v[i]);
        fix_down(0, v, i);
    }
}

void print_vector(vector<int> &v) {
    for (int x: v) {
        cout << x << ' ';
    }
}

bool validate_sorted_vector(vector<int> &v) {
    for (int i=1; i<v.size(); i++) {
        if (v[i] < v[i-1]) return false;
    }
    return true;
}

void gen_testcase(int n) {
    for (int i=1; i<=n; i++) {
        vector<int> v;

        create_random_vector(v);
        heap_sort(v);

        assert(validate_sorted_vector(v));
    }
    cout << "All test cases succeeded!\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    srand(time(NULL));
    gen_testcase(100);

    return 0;
}