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

        if (n & 1)
        {
            cout << (n / 2) << "\n";
        }
        else
        {
            cout << (n / 2 - 1) << "\n";
        }
        
    }

}
