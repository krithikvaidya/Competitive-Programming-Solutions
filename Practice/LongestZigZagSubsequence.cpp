#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> seq(n);

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	vector<vector<int>> longest_zz (n, vector<int>(2));

	longest_zz[0][0] = 1;
	longest_zz[0][1] = 1;

	for (int i = 1; i < n; i++) {

		// longest zz seq ending at index i

		
		for (int j = 0; j < i; j++) {
			// 1. considering seq[i] is greater than previous element
			if (seq[j] < seq[i]) {
				longest_zz[i][0] = max (longest_zz[i][0], longest_zz[j][1] + 1);
			}
			// 2. considering seq[i] is smaller than previous element
			else if (seq[j] > seq[i]) {
				longest_zz[i][1] = max (longest_zz[i][1], longest_zz[j][0] + 1);
			}
		}

	}

	cout << max (longest_zz[n - 1][0], longest_zz[n - 1][1]) << "\n";

}