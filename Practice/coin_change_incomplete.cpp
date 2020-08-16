#include <bits/stdc++.h>

using namespace std;

int solveCoinChange (const vector<int>& den, int remain, vector<int>& lookup) {

	if (remain == 0)
		return 0;

	if (lookup[index] != 0)
		return lookup[index];

	

}

int main () {

	string str = "wOrdbreakproblem";
	vector<string> dict = { "this", "th", "is", "famous", "word", "break",
			"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// convert string to lowercase for case insensitive comparison
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	// for memoization
	vector<int> lookup (str.size());

	cout << solveWordBreak (str, dict, lookup, 0) << "\n";
}