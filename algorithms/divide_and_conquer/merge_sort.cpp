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

void merge_array(int l, int r, vector<int> &v) {
    int m = (l+r) >> 1;
    
    vector<int> v1; v1.assign(v.begin()+l, v.begin()+m+1);
    vector<int> v2; v2.assign(v.begin()+m+1, v.begin()+r+1);

    int i = 0, j = 0, index = l;
    while (i<v1.size() || j<v2.size()) {
        if (i<v1.size() && j<v2.size()) {
            if (v1[i]<v2[j]) {
                v[index] = v1[i];
                index++, i++;
            } else {
                v[index] = v2[j];
                index++, j++;
            }
        } else {
            if (i<v1.size()) {
                v[index] = v1[i];
                index++, i++;
            } else {
                v[index] = v2[j];
                index++, j++;
            }
        }
    }
}

void merge_sort(int l, int r, vector<int> &v) {
    if (l == r) return ;
    int m = (l+r) >> 1;
    merge_sort(l, m, v);
    merge_sort(m+1, r, v);
    merge_array(l, r, v);
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
        merge_sort(0, v.size()-1, v);

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