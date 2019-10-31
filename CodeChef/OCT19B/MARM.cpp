#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long int n, r, m, k;
        cin >> n >> k;
        int a[n];
        for(int j = 0; j < n; j++)
            cin >> a[j];
        if(k >= n)
        {
            r = k % n;
            m = (k/n) % 3;
            for(int j = 0; j < m; j++)
            {
                for(int l = 0; l < n; l++)
                {
                    a[l] = a[l] ^ a[n - l - 1];
                }
            }
            if(n % 2 & 1)
                a[n/2] = 0;
            for(int j = 0; j < r; j++)
            {
                a[j] = a[j] ^ a[n - j - 1];
            }
        }
        else
        {
            for(int j = 0; j < k; j++)
            {
                a[j % n] = (a[j % n]) ^ (a[n - (j%n) - 1]);
            }
        }
        for(int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << "\n";
    }
}
