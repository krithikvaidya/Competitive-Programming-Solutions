#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int y = 0; y < t; y++) {

        int n, m;
        cin >> n >> m;

        vector<string> strings(n);
        map<char, vector<int>> org_occurences;
        map<char, vector<int>> new_occurences;

        for(int i = 0; i < 26; i++) {
            org_occurences[char(i + 97)] = vector<int>(m);
            new_occurences[char(i + 97)] = vector<int>(m);
        }

        for (int i = 0; i < n; i++) {
            cin >> strings[i];
            for(int j = 0; j < m; j++) {
                org_occurences[strings[i][j]][j]++;
            }
        }

        vector<string> outputs(n);

        for (int i = 0; i < n - 1; i++) {
            cin >> outputs[i];
            for(int j = 0; j < m; j++) {
                new_occurences[outputs[i][j]][j]++;
            }
        }

        for (string str: strings) {

            bool flag = true;

            for(int j = 0; j < m; j++) {
                if(org_occurences[str[j]][j] - 1 != new_occurences[str[j]][j]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                cout << str << endl;
                break;
            }
        } 
    }z
}