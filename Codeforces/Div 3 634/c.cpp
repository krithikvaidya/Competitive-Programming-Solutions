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

        vector<int> a(n);

        for (int j = 0; j < n; j++)
            cin >> a[j];

        if (n == 1)
        {
            cout << 0 << "\n";
            continue;

        }

        sort (a.begin(), a.end());

        vector<int> occurences;

        int n_dist = 1;
        int curr_occ_count = 1;

        for (int j = 1; j < n; j++)
        {
            if (a[j] == a[j - 1])
            {
                curr_occ_count++;
            }
            else
            {
                occurences.push_back(curr_occ_count);
                curr_occ_count = 1;
                n_dist++;
            }
            
        }

        occurences.push_back(curr_occ_count);

        sort (occurences.rbegin(), occurences.rend());



        int j = 0;
        while (j < n_dist && occurences[j] >= n_dist)
            j++;

        if (occurences[0] == n_dist)
            cout << n_dist - 1 << "\n";
        else if (occurences[0] > n_dist)
            cout << n_dist << "\n";
        else
        {
            cout << occurences[0] << "\n";
        }

    }

}
