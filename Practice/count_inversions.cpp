
#include <bits/stdc++.h>

using namespace std;

int inversion_count;

void get_inversions (vector<int>& arr, vector<int>& aux, int lb, int ub) {

	if (lb == ub)	return;

	int mid = (lb + ub) / 2;

	get_inversions (arr, lb, mid - 1);
	get_inversions (arr, mid, ub);

	int i = lb;
	int j = mid;
	int k = lb;

	while (i <= mid - 1 && j <= ub) {

		if (arr[i] < arr[j]) {
			aux[k] = arr[i];
			i++;
			inversion_count += (mid - 1 - i);
		}
		else
		{
			aux[k] = arr[j];
			j++;
		}
		k++;

	}

	while (i <= mid - 1) {

		aux[k] = arr[i];
		i++;
		k++;
	
	}

	while (j <= ub) {
		aux[k] = arr[j];
		j++;
		k++;
	}

	for (int i = lb; i <= ub; i++) {
		arr[i] = aux[i];
	}


}



int main() {

	int n;
	cin >> n;
	vector<int> arr(n);

	cout << get_inversions (arr, 0, n - 1);

}