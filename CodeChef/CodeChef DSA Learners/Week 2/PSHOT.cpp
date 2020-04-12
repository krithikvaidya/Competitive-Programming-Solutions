#include <bits/stdc++.h>

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
        int n;
        cin >> n;
        cin.ignore();

        string s;
        cin >> s;

        int shots_left_a = n, shots_left_b = n;
        int b_goals = 0, a_goals = 0;

        bool flag = false;
        for (int j = 0; j < 2 * n; j++)
        {
            if (j & 1)
            {
                shots_left_b--;
                if (s[j] == '1')
                {
                    b_goals++;
                    if (b_goals - a_goals > shots_left_a)
                    {
                        cout << (j + 1) << "\n";
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if (a_goals - b_goals > shots_left_b)
                    {
                        cout << (j + 1) << "\n";
                        flag = true;
                        break;
                    }
                }
                
            }

            else
            {
                shots_left_a--;
                if (s[j] == '1')
                {
                    a_goals++;
                    if (a_goals - b_goals > shots_left_b)
                    {
                        cout << (j + 1) << "\n";
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if (b_goals - a_goals > shots_left_a)
                    {
                        cout << (j + 1) << "\n";
                        flag = true;
                        break;
                    }
                }
                
            }

        }
        if (!flag)
            cout << (2 * n) << "\n";
    }
}