#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m;
    vector<int> curr_max_valu;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int a[n];
        int curr_lcm = 1;
        int curr_max_lcm, curr_max_value;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            curr_lcm = (a[j] * curr_lcm)/(__gcd(a[j], curr_lcm)); 
        }

        curr_max_lcm = curr_lcm;
        curr_max_value = 1;

        for (int j = 1; j <= m; j++)
        {
            if ((j * curr_lcm)/(__gcd(j, curr_lcm)) > curr_max_lcm)
            {
                curr_max_lcm = (j * curr_lcm)/(__gcd(j, curr_lcm));
                curr_max_value = j;
            }
        }

        curr_max_valu.push_back(curr_max_value);
    }

    for (int i = 0; i < t; i++)
        cout << curr_max_valu[i] << "\n";
}