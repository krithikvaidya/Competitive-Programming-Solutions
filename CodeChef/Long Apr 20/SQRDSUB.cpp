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

        int a[n];

        for (int j = 0; j < n; j++)
            cin >> a[j];

        int prev = -1, prev_prev = -1;
        long long sum = 0ll;

        for (int j = 0; j < n; j++)
        {
            if (a[j] % 4 == 0)
            {
                sum += j + 1;
                prev_prev = prev;
                prev = j;
            }

            else if (a[j] % 2 == 0)
            {
                if (prev != -1)
                {
                    sum += j - (j - prev - 1);
                }

                prev_prev = prev;
                prev = j;
            }

            else
            {
                if (prev != -1 && prev_prev != -1)
                {
                    if (a[prev] % 4 == 0)
                        sum += (j + 1);
                    else
                    {
                        sum += (j + 1) - (prev - prev_prev);
                    }
                    
                }

                else if (prev != -1 && prev_prev == -1)
                {
                    if (a[prev] % 4 == 0)
                        sum += j + 1;
                    else
                    {
                        sum += (j - prev);
                    }
                    
                }
                
                else
                {
                    sum += j + 1;
                }
                
            }
            
        }

        cout << sum << "\n";
    }
}