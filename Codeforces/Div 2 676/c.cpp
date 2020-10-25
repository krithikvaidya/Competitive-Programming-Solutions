#include <bits/stdc++.h>

using namespace std;

int main () {

    string s;
    cin >> s;

    cout << 5 << "\n";

    int size = s.size();
    size += size - 2;
    size += size - 2;
    size += 1;
    size += size - 2;

    cout << "R 2\nR 2\nL 2\nR 2\nR " << size - 1 << "\n";

}