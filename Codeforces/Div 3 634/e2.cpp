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

        vector<int> occurences[201];
        vector<int> pos[201];

        for (int k = 1; k < 201; k++)
        {
            occurences[k].push_back(0);
        }   

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];

            for (int k = 1; k < 201; k++)
            {
                occurences[k].push_back(occurences[k][j]);
            }

            occurences[a[j]][j + 1]++;

            pos[a[j]].push_back(j);
            
        }

        // at index j of occurences[x], the value x has occurent occurences[j][x] number of times

        int global_max = 0;
        for (int j = 1; j < 201; j++)
        {
            int k = 0;
            int curr = 0;
            while (k < 201 && (pos[j].size() - k - 1))
            {
                curr = 2 * (k + 1);
                for (int l = pos[j][k] + 1; l <= pos[j].size() - k)
                curr += (occurences[[pos[j].size() - k] - occurences[pos[j][k]]);
            }
        }

    }

}

