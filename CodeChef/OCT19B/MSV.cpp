#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k;
    cin >> t;
    int max_star;
    for(int i = 0; i < t; i++)
    {
        max_star = 0;
        cin >> n;
        vector<int> no_of_divisors(1000001);
        int a[n];
        for(int j = 0; j < n; j++)
        {
            cin >> a[j];
            if(no_of_divisors[a[j]] > max_star)
                max_star = no_of_divisors[a[j]];
            for (int k=1; k<=sqrt(a[j]); k++)
            {
                if (a[j]%k == 0)
                {
                    if (a[j]/k == k)
                        no_of_divisors[k]++;
                    else
                    {
                        no_of_divisors[k]++;
                        no_of_divisors[a[j]/k]++;
                    }
                }
            }
        }
        cout << max_star << "\n";
    }
}
