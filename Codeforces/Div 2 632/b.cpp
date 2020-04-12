#include <bits/stdc++.h>

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

        int a[n], b[n];

        for (int j = 0; j < n; j++)
            cin >> a[j];

        for (int j = 0; j < n; j++)
            cin >> b[j];

        bool one_occ = false, minone = false;
        bool flag = true;

        for (int j = 0; j < n; j++)
        {
            if (a[j] < b[j])
            {
                if (one_occ)
                {
                    if (a[j] == 1)
                        one_occ = true;
                    else if (a[j] == -1)
                        minone = true;

                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (a[j] > b[j])
            {
                if (minone)
                {
                    if (a[j] == 1)
                        one_occ = true;
                    else if (a[j] == -1)
                        minone = true;
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }

            if (a[j] == 1)
                one_occ = true;
            else if (a[j] == -1)
                minone = true;

            if (minone && one_occ)
                break;
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

