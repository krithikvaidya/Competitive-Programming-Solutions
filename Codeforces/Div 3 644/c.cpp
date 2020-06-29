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

        vector <int> a(n);

        for (int j = 0; j < n; j++)
            cin >> a[j];

        sort (a.begin(), a.end());
        bool exists = false;
        int o = 0, e = 0;

        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] & 1)
                o++;
            else
            {
                e++;
            }

            if (a[j + 1] - a[j] == 1)
                exists = true;
            
        }

        if (a[n - 1] & 1)
            o++;
        else
        {
            e++;
        }

        if (o % 2 == 0 && e % 2 == 0)
            cout << "YES\n";
        else if (o % 2 == 1 && e % 2 == 1)
        {
            if (exists)
                cout << "YES\n";
            else
            {
                cout << "NO\n";
            }
            
        }
        else
        {
            cout << "NO\n";
        }
        
        
    }

}
