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

    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;

        int r1 = 2;
        for (int i = 1; i < n; i++)
            r1 += r1 * 2;

        long long res = r1;
        int pow = 1;
        int r2 = 2;
        cout << res << "\n";
        for (int i = 1; i < n/2 - 1; i++)
            r2 *= 2;

        for (int i = n / 2; i < n - 1; i++)
        {
            r2 *= 2;
            res -= r2;
        }

        // cout << res << "\n";

    }

}
