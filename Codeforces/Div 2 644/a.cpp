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
        lli a, b, c, d;
        cin >> a >> b >> c >> d;

        if (b >= a)
        {
            cout << b << "\n";
            continue;
        }

        if (d >= c)
        {
            cout << -1 << "\n";
            continue;
        }

        lli ans = b + c * ((a - b) / (c - d));

        if ((b + ((a - b)/(c - d)) * (c - d)) < a)
            ans += c;//(a - ((b + (a - b) / (c - d)) * (c - d));

        // if ((a - b) % (c - d) == 0)
        //     cout << ((a - b) / (c - d)) << "\n";
        // else
        //     cout << ((a - b) / (c - d) + 1) << "\n";

        cout << ans << "\n";
    }

}
