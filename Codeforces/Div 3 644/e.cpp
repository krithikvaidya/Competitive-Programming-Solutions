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
        cin.ignore();

        vector<string> mat(n);

        for (int j = 0; j < n; j++)
        {
            cin >> mat[j];
        }

        

        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (mat[j][k] == '1')
                {
                    if (j == n - 1 || k == n - 1)
                        continue;

                    if (mat[j + 1][k] == '1' || mat[j][k + 1] == '1')
                        continue;

                    flag = false;
                    break;
                }
            }

            if (!flag)
                break;
            
        }

        if (flag)
                cout << "YES\n";
            else
            {
                cout << "NO\n";
            }
    }

}
