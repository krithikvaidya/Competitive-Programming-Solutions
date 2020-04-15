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

        vector<int> a(n);

        for (int j = 0; j < n; j++)
            cin >> a[j];

        sort (a.begin(), a.end());

        int k = n / 2;
        int offset = 1;

        cout << a[k] << " ";
        while (k - offset >= 0 && k + offset < n)
        {
            if ((n & 2) && (k - offset == 0))
                cout << a[k - offset] << " " << a[k + offset];
            else
            {
                cout << a[k - offset] << " " << a[k + offset] << " ";
            }
            
            offset++;
        }

        if (k - offset == 0)
            cout << a[0];
        else if (k + offset == n - 1)
            cout << a[n - 1];

        cout << "\n";

    }

}
