#include <bits/stdc++.h>

using namespace std;

bool solveWordBreak (string str, const vector<string>& dict, vector<int>& lookup, int index) {

	if (str.empty())
		return true;

	if (lookup[index] == -1)
		return false;
	else if (lookup[index] == 1)
		return true;

	string prefix;

	for (int i = 1; i <= str.size(); i++) {

		prefix = str.substr (0, i);

		if (find (dict.begin(), dict.end(), prefix) != dict.end()) {
			if (solveWordBreak (str.substr (i), dict, lookup, index + i)) {

				lookup[index] = 1;
				return true;
			}	
		}
	}

	lookup[index] = -1;
	return false;

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