#include <bits/stdc++.h>

using namespace std;

void create_random_vector(vector<int> &v) {
    for (int i=0; i<100; i++) {
        v.push_back(rand() % 1000 + 1);
    }
}

void insertion_sort_with_gap(vector<int> &v, int index, int gap) {
    for (int i=index-gap; i>=0; i-=gap) {
        int temp = v[i];
        int pos = i+gap;
        while (pos<v.size() && v[pos]<temp) {
            v[pos-gap] = v[pos];
            pos += gap;
        }
        v[pos-gap] = temp;
    }
}

void shell_sort(vector<int> &v) {
    vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};

    for (int i=0; i<gaps.size(); i++) {
        for (int j=v.size()-1; j>=v.size()-gaps[i]; j--) {
            insertion_sort_with_gap(v, j, gaps[i]);
        }
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
        shell_sort(v);

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