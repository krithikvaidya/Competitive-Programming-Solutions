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
        int x, n, m;
        cin >> x >> n >> m;

        while (x >= 21 && n > 0)
        {
            n--;
            x = (x / 2) + 10;
        }

        if (x > 10 * m)
            cout << "NO\n";
        else
            cout << "YES\n";
        


    }

}
