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

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int a[n];

        vector<int> occurences[27];

        for (int k = 1; k < 27; k++)
        {
            occurences[k].push_back(0);
        }   

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];

            for (int k = 1; k < 27; k++)
            {
                occurences[k].push_back(occurences[k][j]);
            }

            occurences[a[j]][j + 1]++;

        }

        int super_max = 0;

        for (int j = 0; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                int left_appcount, right_appcount;
                int max_appcount = 0;

                for (int l = 1; l <= 26; l++)
                {
                    left_appcount = occurences[l][j];
                    right_appcount = occurences[l][n] - occurences[l][k + 1];
                    max_appcount = max (max_appcount, min (left_appcount, right_appcount));
                }
                
                int wew = 0;

                for (int l = 1; l <= 26; l++)
                {
                    wew = max (wew, occurences[l][k + 1] - occurences[l][j]);
                }


                super_max = max (super_max, wew + 2 * max_appcount);
            }
        }

        
        cout << super_max << "\n";

    }

}

