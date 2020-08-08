#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;


int get_position (int lb, int ub, vector<int>& arr) {

	int mid = (lb + ub) / 2;
	int prev, next;

	prev = (mid - 1 + n) % n;
	next = (mid + 1) % n;

	if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {

		return mid;

	}

	if (arr[mid] > arr[ub]) return get_position (mid + 1, ub, arr);

	return get_position (lb, mid - 1, arr);

}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr;
	int n, temp;
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> temp;
		arr.push_back (temp);

	}

	cout << get_position (0, n - 1, arr) << "\n";

}
