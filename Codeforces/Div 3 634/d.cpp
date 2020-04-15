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
    cin.ignore();

    for (int i = 0; i < t; i++)
    {
        vector<string> sud(9);

        for (int j = 0; j < 9; j++)
            cin >> sud[j];

        for (int j = 0; j < 3; j++)
        {
            if (sud[j][j * 3] != '9')
                sud[j][j * 3] += 1;
            else
            {
                sud[j][j * 3] = '1';
            }
            
        }


        
        int k = 1;
        for (int j = 3; j < 6; j++)
        {
            if (sud[j][k] != '9')
                sud[j][k] += 1;
            else
            {
                sud[j][k] = '1';
            }
            k += 3;
        }


        
        k = 2;
        for (int j = 6; j < 9; j++)
        {
            if (sud[j][k] != '9')
                sud[j][k] += 1;
            else
            {
                sud[j][k] = '1';
            }
            k += 3;
        }

        for (int j = 0; j < 9; j++)
            cout << sud[j] << "\n";
    }

}
