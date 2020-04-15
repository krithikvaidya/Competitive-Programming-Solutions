#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<pair<int, int> > multiple_pairs;

    for (int i = 1; i < k; i++)
    {
        if (k % i == 0)
        {
            if (i <= (k / i))
            {
                multiple_pairs.push_back(make_pair(i, (k / i)));
            }
            else
            {
                break;
            }
            
        }
    }

    vector<int> consec_a, consec_b;

    int len = 0;
    int prev = 0;

    for (int i = 0; i < n; i++)
    {
        if (prev == 1 && a[i] == 1)
            len++;
        else if (prev != 1 && a[i] == 1)
        {
            len = 1;
            prev = 1;
        }
        else if (prev == 1 && a[i] != 1)
        {
            consec_a.push_back(len);
            prev = 0;
            len = 0;
        }
        
    }

    for (int i = 0; i < m; i++)
    {
        if (prev == 1 && b[i] == 1)
            len++;
        else if (prev != 1 && b[i] == 1)
        {
            len = 1;
            prev = 1;
        }
        else if (prev == 1 && b[i] != 1)
        {
            consec_b.push_back(len);
            prev = 0;
            len = 0;
        }
        
    }

    sort (consec_a.begin(), consec_a.end());
    sort (consec_b.begin(), consec_b.end());

    long long int rect = 0;

    for (int i = 0; i < consec_a.size(); i++)
    {

        int check;
        if (k % consec_a[i] == 0)
            check = k / consec_a[i];

        else
        {
            check = k / consec_a[i] + 1;
        }
        
        int index = lower_bound(b.begin(), b.end(), check) - b.begin();
        if (index >= m) continue;

        for (int j = index; j < m; j++)
        {
            int row = consec_a[i] - k;
        }
    }
}
