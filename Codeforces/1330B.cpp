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

        int a[n];
        int max = INT_MIN;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (a[j] > max)
                max = a[j];
        }

        int size1 = max;
        int size2 = n - size1;

        vector<int> app(n + 1);
        bool flag = true;

        for (int j = 0; j < size1; j++)
        {
            if (a[j] > size1)
            {
                flag = false;
                break;
            }

            app[a[j]]++;

            if (app[a[j]] > 1)
            {
                flag = false;
                break;
            }
        }

        std::fill(app.begin(), app.end(), 0);

        for (int j = size1; j < n; j++)
        {
            if (a[j] > size2)
            {
                flag = false;
                break;
            }

            app[a[j]]++;

            if (app[a[j]] > 1)
            {
                flag = false;
                break;
            }
        }   
        int ctr1 = 0, ctr2 = 0;

        if (flag)
        {
            ctr1 = 1;
        }

        flag = true;
        std::fill(app.begin(), app.end(), 0);

        for (int j = 0; j < size2; j++)
        {
            if (a[j] > size2)
            {
                flag = false;
                break;
            }

            app[a[j]]++;

            if (app[a[j]] > 1)
            {
                flag = false;
                break;
            }
        }

        std::fill(app.begin(), app.end(), 0);

        for (int j = size2; j < n; j++)
        {
            if (a[j] > size1)
            {
                flag = false;
                break;
            }

            app[a[j]]++;

            if (app[a[j]] > 1)
            {
                flag = false;
                break;
            }
        }   

        if (flag)
        {
            ctr2 = 1;
        }
        
        if (ctr1 && ctr2 && (size1 != size2))
        {
            cout << 2 << "\n";
            cout << size1 << " " << size2 << "\n";
            cout << size2 << " " << size1 << "\n";
        }

        else if (ctr1 && ctr2 && (size1 == size2))
        {
            cout << 1 << "\n";
            cout << size1 << " " << size2 << "\n";
        }

        else if (ctr1 && !ctr2)
        {
            cout << 1 << "\n";
            cout << size1 << " " << size2 << "\n";
        }

        else if (!ctr1 && ctr2)
        {
            cout << 1 << "\n";
            cout << size2 << " " << size1 << "\n";
        }

        else
        {
            cout << 0 << "\n";
        }
        
    }

}
