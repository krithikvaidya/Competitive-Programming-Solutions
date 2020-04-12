#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];

    for (int j = 0; j < n; j++)
        cin >> a[j];

    int least_possb = numeric_limits<int>::max();

    map <int, vector<int> > divisions;
    vector <int> candidates;

    for (int j = 0; j < n; j++)
    {
        int divcount = 0;
        while (a[j] > 0)
        {
            divisions[a[j]].push_back(divcount);
            
            if (divisions[a[j]].size() == k)
            {
                candidates.push_back(a[j]);
            }

            divcount++;
            a[j] /= 2;
        }

        divisions[0].push_back(divcount);
    }

    for (int candidate: candidates)
    {
        sort (divisions[candidate].begin(), divisions[candidate].end());
        int sum = 0;

        for (int j = 0; j < k; j++)
            sum += divisions[candidate][j];

        if (sum < least_possb)
            least_possb = sum;
    }

    cout << least_possb;
}