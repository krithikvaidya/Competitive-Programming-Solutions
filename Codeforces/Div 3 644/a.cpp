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
        int a, b;
        cin >> a >> b;

        int c = max (a, b);
        int d = min (a, b);
        if (c >= 2 * d)
            cout << c * c << "\n";
        else
        {
            cout << 4 * d * d << "\n";
        }
        
    }

}
