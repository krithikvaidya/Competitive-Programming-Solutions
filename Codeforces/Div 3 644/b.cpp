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

        vector <int> s(n);

        for (int j = 0; j < n; j++)
            cin >> s[j];

        sort (s.begin(), s.end());

        int min_diff = INT_MAX;

        for (int j = 0; j < n - 1; j++)
        {
            if (s[j + 1] - s[j] < min_diff)
                min_diff = s[j + 1] - s[j];
        }

        cout << min_diff << "\n";

    }

}
