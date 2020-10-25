#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    vector<int> swaps;
    vector<vector<pair<int, int>>> prs;

    for (int a = 0; a < t; a++) {

        int n;
        cin >> n;

        vector<vector<char>> grid (n, vector<char>(n));

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                cin >> grid[i][j];

            }
        }

        int swap = 0;
        vector<pair<int, int> > coord;

        if ((grid[0][2] == grid[1][1]) && (grid[0][2] == grid[2][0])) {

            if (grid[0][1] == grid[1][1]) {
                coord.push_back ({1, 2});
                swap++;
            }

            if (grid[1][0] == grid[1][1]) {
                coord.push_back ({2, 1});
                swap++;
            }
        }

        else if (grid[1][0] != grid[0][1]) {

            if (grid[1][0] == grid[1][1]) {

                if (grid[0][1] != grid[0][2]) {
                    
                }

                else {
                    swap++;
                    coord.push_back ({1, 3});
                }

                if (grid[2][0] == grid[1][0]) {
                    swap++;
                    coord.push_back ({2, 1});
                }

            }

            else {

                if (grid[1][0] != grid[2][0]) {

                }

                else {
                    swap++;
                    coord.push_back ({3, 1});
                }

                if (grid[0][2] == grid[0][1]) {
                    swap++;
                    coord.push_back ({1, 2});
                }

            }
            

        }

        else {

            if (grid[0][1] == grid[0][2]) {
                swap++;
                coord.push_back ({1, 3});
            }

            if (grid[0][1] == grid[1][1]) {
                swap++;
                coord.push_back ({2, 2});
            }

            if (grid[0][1] == grid[2][0]) {
                swap++;
                coord.push_back ({3, 1});
            }



        }

        swaps.push_back (swap);
            prs.push_back(coord);
    


    }

    for (int i = 0; i < swaps.size(); i++) {
        cout << swaps[i] << "\n";
        for (auto p: prs[i]) {
            cout << p.first << " " << p.second << "\n";
        }
        
    }

}