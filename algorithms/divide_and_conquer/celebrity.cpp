#include <bits/stdc++.h>

using namespace std;

bool B[21][21];
int n;

int find_celeb(int start, int stop) {
	if (start == stop) {
		for (int i = 1; i <= n; i++) {
			if (B[start][i]) return -1;
			if (i != start && !B[i][start]) return -1;
		}
		return start;
	}

	if (B[start][stop]) {
		return find_celeb(start+1, stop);
	} else {
		return find_celeb(start, stop+1);
	}
} 

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> B[i][j];
    	}
    }

    int celeb = find_celeb(1, n);

    if (celeb == -1) {
    	cout << "No celebrity\n";
    } else {
    	cout << "Celebrity: " << celeb << '\n';
    }

    return 0;
}