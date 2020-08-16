#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main () {

	string str = "Hi hello kthxbye";

	stringstream stream(str);

	vector<string> tokens;

	string temp;
	char delimiter = ' ';

	while (getline (stream, temp, delimiter)) {
		tokens.push_back (temp);
	}

	for (string token: tokens) cout << token << "\n";


}