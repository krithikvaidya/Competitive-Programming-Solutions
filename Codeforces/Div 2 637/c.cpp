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
        int temp;

        vector<pair<int, int>> p;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            p.push_back(make_pair(temp, j));
        }

        vector<int> next_unocc(n);
        vector<int> least_prev_occ(n);

        vector<int> count(n);

        for (int j = 0; j < n; j++)
        {
            count[j] = 1;
            next_unocc[j] = j;
            least_prev_occ[j] = -1;
        }

        int smallest_occ_index = -1;
        int curr_index;
        int curr_count = 0;

        sort(p.begin(), p.end());
        bool flag = true;

        for (auto pr : p)
        {

            if (pr.first == 1)
            {
                smallest_occ_index = pr.second;
                curr_index = pr.second + 1;
                continue;
            }

            // second = index to be placed at.
            if (pr.second < smallest_occ_index)
            {
                smallest_occ_index = pr.second;
                curr_index = pr.second + 1;
            }

            else
            {
                if (pr.second == curr_index)
                {
                    curr_index++;
                    continue;
                }
                else
                {
                    cout << "No\n";
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
            cout << "Yes\n";
    }
}
