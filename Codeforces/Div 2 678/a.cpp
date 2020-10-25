
#include <bits/stdc++.h>

using namespace std;

int main () {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        int n, m;
        cin >> n >> m;

        int sum = 0, temp;

        for (int j = 0; j < n; j++) {
            cin >> temp;
            sum += temp;
        }

        if (sum == m) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    

}