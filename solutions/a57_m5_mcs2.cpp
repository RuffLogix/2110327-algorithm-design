#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    srand(time(NULL));

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = -1e9;

    int t = 10; // choose starting index t times randomly, more t more accuracy.
    while (t--) {
        int cur_sum = 0;
        int begin_index = 1;
        for (int i = rand()%n + 1; i <= n*2; i++) {
            int index = i%n + 1;
            int x = arr[index]; 

            if ((cur_sum + x < x) || (begin_index == index)) {
                begin_index = index;
                cur_sum = x;
            } else {
                cur_sum += x;
            }

            ans = max(ans, cur_sum);
        }
    }

    cout << ans << '\n';

    return 0;
}