#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;

    int n;
    int prev_type;

    for (int i = 0; i < q; i++)
    {
        cin >> n;
        int t[n];
        bool flag = 1;
        int simult_similar = -1;

        for (int j = 0; j < n; j++)
        {
            cin >> t[j];
            if (j == 0)
                prev_type = t[j];
            else
            {
                if (t[j] != prev_type)
                {
                    flag = false;
                    prev_type = t[j];
                }
                else
                {
                    simult_similar = j;
                }
                
            }
        }

        if (flag)
        {
            cout << "1\n";
            for (int j = 0; j < n; j++)
                cout << "1 ";
            cout << "\n";
            continue;
        }

        if (t[0] == t[n - 1] && (simult_similar == -1))
            simult_similar = 0;

        if (n & 1)
        {
            if (simult_similar != -1 && simult_similar != 0)
            {
                cout << "2\n";
                int prev = 2;
                for (int j = 0; j < n; j++)
                {
                    if (j == simult_similar)
                        cout << prev << " ";
                    else
                    {
                        if (prev == 1)
                            prev = 2;
                        else
                            prev = 1;
                        cout << prev << " ";
                    }
                    
                }
            }
            else if (simult_similar == 0)
            {
                cout << "2\n";
                int prev = 2;
                for (int j = 0; j < n; j++)
                {
                    if (j == n - 1)
                        cout << 1;
                    else
                    {
                        if (prev == 1)
                            prev = 2;
                        else
                            prev = 1;
                        cout << prev << " ";
                    }
                    
                }
            }
            else 
            {
                cout << "3\n";
                for (int j = 0; j < n - 1; j++)
                {
                    if (j & 1)
                        cout << "2 ";
                    else
                    {
                        cout << "1 ";
                    }
                    
                }

                cout << "3";
            }
        }
        else
        {
            if (flag)
            {
                cout << "1\n";
                for (int j = 0; j < n; j++)
                    cout << "1 ";
            }
            else
            {
                cout << "2\n";
                for (int j = 0; j < n; j++)
                {
                    if (j & 1)
                        cout << "2 ";
                    else
                        cout << "1 ";
                }
            }

            
        }

        cout << "\n";
        
    }
}