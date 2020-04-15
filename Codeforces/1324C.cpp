#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    
    for (int i = 0; i < t; i++)
    {
        string s, st;
        s.push_back('R');
        cin >> st;

        for (int j = 0; j < st.size(); j++)
            s.push_back(st[j]);
            
        s.push_back('R');

        int max_diff = 0;
        int prev_index = 0;

        for (int j = 1; j < s.size(); j++)
        {
            if (s[j] == 'R')
            {
                max_diff = max (max_diff, j - prev_index);
                prev_index = j;
            }
        }

        cout << max_diff << "\n";

    }

}
