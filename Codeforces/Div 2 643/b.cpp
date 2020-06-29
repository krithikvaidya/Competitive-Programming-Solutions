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

        vector<int> inex(n);
        for (int j = 0; j < n; j++)
            cin >> inex[j];

        sort (inex.begin(), inex.end());

        int grp_count = 0;
        int curr_per_ct = 0;
        int reqd_per_count = 0;

        for (int j = 0; j < n; j++)
        {
            reqd_per_count = inex[j];
            if (++curr_per_ct >= reqd_per_count)
            {
                grp_count++;
                curr_per_ct = 0;
                reqd_per_count = 0;
            }
        }

        cout << grp_count << "\n";
    }

}
