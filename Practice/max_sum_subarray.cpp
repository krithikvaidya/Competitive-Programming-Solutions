#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;


int get_max (int lb, int ub, vector<int>& arr) {

	if (lb == ub)	return arr[lb];

	int midleft_maxsum = INT_MIN;
	int sum = 0;
	int mid = ( lb + ub ) / 2;

	for (int i = mid; i >= lb; i--) {
		sum += arr[i];

		if (sum > midleft_maxsum) midleft_maxsum = sum;
	}

	int midright_maxsum = INT_MIN;
	sum = 0;
	
	for (int i = mid + 1; i <= ub; i++) {
		sum += arr[i];

		if (sum > midright_maxsum) midright_maxsum = sum;
	}

	int left_right_max = max (get_max (lb, mid - 1, arr), get_max (mid + 1, ub, arr));

	return max (left_right_max, midleft_maxsum + midright_maxsum);

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

	cout << get_max (0, n - 1, arr) << "\n";

}
