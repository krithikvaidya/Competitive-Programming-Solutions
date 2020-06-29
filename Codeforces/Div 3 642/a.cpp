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
        int n, m;
        cin >> n >> m;

        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        if (n == 2)
            cout << m << "\n";
        else
        cout << (m * 2) << "\n";


    }

}
