#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n);
    int t, prev_index = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (i == 0)
            a[i] = make_pair(t, 0);
        
        else if (t % a[i - 1].first == 0)
            a[i] = make_pair(t, a[i - 1].second);

        else if (t % a[i - 1].first != 0)
            a[i] = make_pair(t, i);
    }

    int op_type, i, val;

    for (int y = 0; y < q; y++)
    {
        cin >> op_type;

        if (op_type == 1)
        {
            cin >> i >> val;

            if (a[i].second == i)
            {
                if (i > 0 && i < n - 1)
                {
                    if (a[i + 1].second == i)
                    {
                        if (a[i + 1].first % val == 0)
                        {
                            a[i].first = val;
                        }
                        else
                        {
                            a[i].first = val;
                            a
                        }
                    }
                }
            }
            else if (i == n - 1)
            {

            }
            else
            {
                if (val % a[i])
            }
        }
        else
        {
            cin >> i;
        }


        
    }

}
