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
        string s;
        cin >> s;

        int od = -1, td = -1, thrd = -1, min_len = INT_MAX;
        for (int j = 0; j < s.size(); j++)
        {
            char ch = s[j];
            if (ch == '1' || ch == '2' || ch == '3')
            {
                if (ch == '1')
                    od = 0;
                if (ch == '2')
                    td = 0;
                if (ch == '3')
                    thrd = 0;

                if (od != -1 && td != -1 && thrd != -1 && ((max ({od, td, thrd}) - min ({od, td, thrd })) < min_len))
                    min_len = max ({od, td, thrd}) - min ({od, td, thrd });
            }

            if (od != -1)
                od++;
            if (td != -1)
            td++;

            if (thrd != -1)
            thrd++;
        }

        if (min_len == INT_MAX)
            cout << 0 << "\n";
        else
        {
            cout << min_len + 1 << "\n";
        }
        
    }

}
