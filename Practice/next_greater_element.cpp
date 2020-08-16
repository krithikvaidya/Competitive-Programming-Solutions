#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr = {5, 10, -1, 3, 88, 41, 5000};
	vector<int> next_greater(arr.size());

	stack<pair<int, int>> enc;

	for (int i = 0; i < arr.size(); i++) {

		while (!enc.empty() && enc.top().first < arr[i]) {

			next_greater[enc.top().second] = arr[i];
			enc.pop();

		}

		enc.push ({arr[i], i});

	}

	while (!enc.empty()) {
		next_greater[enc.top().second] = -1;
		enc.pop();
	}

	cout << "\n";

	for (int a: next_greater) {
		cout << a << " ";
	}

	cout << "\n";

}

