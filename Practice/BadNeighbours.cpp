#include <bits/stdc++.h>

using namespace std;

int max_don;

void calc_don (vector<int>& A, int index, vector<int> oc, int n, int curr_don) {

	if (index == n - 1) {

		if (!oc[n - 2] && !oc[0]) {
			curr_don += A[n - 1];
		}

		max_don = max (max_don, curr_don);
		return;
	}

	calc_don (A, index + 1, oc, n, curr_don);

	if ((index - 1 >= 0 && !oc[index - 1]) || index == 0) {
		curr_don += A[index];
		oc[index] = 1;
		calc_don (A, index + 1, oc, n, curr_don);
	}

}

int main() {

	int n;
	cin >> n;

	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<int> oc(n);

	calc_don (A, 0, oc, n, 0);

	cout << max_don << "\n";


}