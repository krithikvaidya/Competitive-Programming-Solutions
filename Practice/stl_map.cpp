#include <iostream>
#include <map>

using namespace std; 

int main() {

	map <string, int> mp = {make_pair ("hi", 5), make_pair ("big", 0)};

	mp.insert (make_pair ("hii", 5));
	mp.insert (make_pair ("hii", 10));
	mp.insert (make_pair ("zzww", 13));
	mp.insert (pair<string, int>("aawwwa", 999));

	mp.erase ("hii");
	cout << mp.size() << "\n";

	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {

		cout << it -> first << ": " << it -> second << "\n";

	}

	mp.clear();
	cout << mp.empty();

}