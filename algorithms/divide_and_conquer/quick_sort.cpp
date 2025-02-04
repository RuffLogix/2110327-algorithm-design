#include <bits/stdc++.h>

using namespace std;

void create_random_vector(vector<int> &v) {
    for (int i=0; i<100; i++) {
        v.push_back(rand() % 1000 + 1);
    }
}

int hoare_partition(int l, int r, vector<int> &v) {
    int pivot = v[l + rand() % (r - l)];
    int start = l - 1;
    int stop = r + 1;

    while (true) {
        do { start += 1; } while (v[start] < pivot);
        do { stop -= 1; } while (v[stop] > pivot);
        if (start >= stop) return stop;
        swap(v[start], v[stop]);
    }
}

void quick_sort(int l, int r, vector<int> &v) {
    if (l == r) return ;
    int pivot = hoare_partition(l, r, v);
    quick_sort(l, pivot, v);
    quick_sort(pivot+1, r, v);
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
        quick_sort(0, v.size()-1, v);

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