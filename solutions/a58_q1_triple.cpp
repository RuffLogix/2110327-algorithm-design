#include <bits/stdc++.h>

using namespace std;

int arr[1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    while (m--) {
        int x;
        cin >> x;

        bool found = false;
        for (int i = 1; i <= n - 2 && !found; i++) {
            for (int j = i+1; j <= n - 1 && !found; j++) {
                int remainder = x - (arr[i] + arr[j]);
                if (remainder < arr[j]) break;
                if (binary_search(arr+1+j, arr+1+n, remainder)) {
                    found = true;
                }
            }
        }

        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}