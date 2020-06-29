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

        cin.ignore();

        vector<string> a(n);

        for (int j = 0; j < n; j++)
            cin >> a[j];
        
        string str = a[0];
        for (int j = 0; j < m; j++)
        {
            bool poss = true;
            for (int k = 0; k < 26; k++)
            {
                str[j] = char(k + 97);
                for (int l = 0; l < n; l++)
                {
                    for (int o = 0; o < m; o++)
                    {
                        if (str[o] != )
                }
            }
        }

    }

}
