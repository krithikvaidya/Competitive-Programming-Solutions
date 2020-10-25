
#include <bits/stdc++.h>

using namespace std;

int main () {

    int t;
    cin >> t;

    for (int a = 0; a < t; a++) {

        int n;
        cin >> n;

        vector <vector<int>> grid (n, vector<int>(n));

        for (int i = 0; i < n; i++) {

            grid[i][i] = 1;
            grid[i][(i + 1) % n] = 1;

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        
    }
    


}