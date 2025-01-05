#include <bits/stdc++.h>

using namespace std;

void create_random_vector(vector<int> &v) {
    for (int i=0; i<100; i++) {
        v.push_back(rand() % 1000 + 1);
    }
}

void selection_sort(vector<int> &v) {
    int n = v.size();
    for (int i=n-1; i>=0; i--) {
        int index = i;
        for (int j=i-1; j>=0; j--) {
            if (v[index] < v[j]) {
                index = j;
            }
        }
        swap(v[i], v[index]);
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
        selection_sort(v);

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