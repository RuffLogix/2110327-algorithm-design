#include <bits/stdc++.h>

using namespace std;

int arr[200001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);    

    int n, w;
    cin >> n >> w;

    srand(time(NULL));

    int ans = -2e9;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];    
    }

    int t = 1000; // choose starting index t times randomly, more t more accuracy.
    while (t--) {
        int width = 0;
        int sum = 0;
        for (int i = rand()%n + 1; i <= n; i++) {
            if (sum + arr[i] < arr[i]) {
                sum = arr[i];
                width = 1;
            } else {
                if (width == w) {
                    width -= 1;
                    sum -= arr[i - w];
                }
                sum += arr[i];
                width += 1;
            }
            ans = max(ans, sum);
        } 
    }

    cout << ans << '\n';

    return 0;
}