#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int smallest_edit_dist (vector<vector<int>> &cache, string X, string Y, int i, int j) {

	if (i == X.size() || j == Y.size()) {
		return abs (int (X.size() - Y.size()));
		
	}

	if (cache[i][j] != -1)
		return cache[i][j];

	if (X[i] == Y[j])

		cache[i][j] = smallest_edit_dist (cache, X, Y, i + 1, j + 1);
		

	else {

		// edit
		cache[i][j] = min ({1 + smallest_edit_dist (cache, X, Y, i + 1, j + 1), 1 + smallest_edit_dist (cache, X, Y, i + 1, j), 1 + smallest_edit_dist (cache, X, Y, i, j + 1)});
		
	}

	return cache[i][j];

}


int main()
{

	string str1, str2;
	cin >> str1;
	cin >> str2;

	vector<vector<int>> cache (str1.size(), vector<int>(str2.size(), -1));

	cout << "Edit Distance: " << smallest_edit_dist (cache, str1, str2, 0, 0) << "\n";

}
