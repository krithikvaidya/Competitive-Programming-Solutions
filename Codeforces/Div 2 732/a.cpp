#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int y = 0; y < t; y++) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> increase;
        vector<int> decrease;

        for (int i = 0; i < n; i++) {
            if (a[i] - b[i] > 0) {
                for(int j = 0; j < a[i] - b[i]; j++)
                    decrease.push_back(i + 1);
            }

            else if (a[i] - b[i] < 0) {
                for(int j = 0; j < b[i] - a[i]; j++)
                    increase.push_back(i + 1);
            }
        }

        if(increase.size() != decrease.size()) 
            cout << -1 << "\n";
        else {
            cout << increase.size() << "\n";
            for(int i = 0; i < increase.size(); i++) {
                cout << decrease[i] << " " << increase[i] << "\n";
            }
        }

    }
    

}