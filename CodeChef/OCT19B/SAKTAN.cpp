#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    long long int n, m, q;
    long long int ctr;
    for(int i = 0; i < t; i++)
    {
        ctr = 0ll;
        cin >> n >> m >> q;
        long long int x, y;
        vector<int> row(n);
        vector<int> col(m);
        for(long long int j = 0ll; j < q; j++)
        {
            cin >> x >> y;
            row[--x]++;
            col[--y]++;
        }
        long long int ctr1 = 0ll;
        long long int ctr2 = 0ll;
        long long int ctr3 = 0ll;
        long long int ctr4 = 0ll;
        for(long long int j = 0ll; j < n; j++)
        {
            if(row[j] & 1)
                ctr1++;
            else
                ctr2++;
        }
        for(long long int k = 0ll; k < m; k++)
        {
            if(col[k] & 1)
                ctr3++;
            else
                ctr4++;
        }
        cout << ((ctr1 * ctr4) + (ctr2 * ctr3)) << "\n";
    }
}
