#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int seniority[n];

    for (int i = 0; i < n; i++)
        cin >> seniority[i];

    lli fear = 1ll;

    priority_queue<pair<int, int> > prev_ranks;

    for (int i = 0; i < n; i++)
    {
        while (prev_ranks.size() && (prev_ranks.top().first > seniority[i]))
        {
            fear = ((fear) * (i - prev_ranks.top().second + 1)) % 1000000007ll;
            prev_ranks.pop();
        }

        prev_ranks.push(make_pair(seniority[i], i));

    }
    
    cout << fear;
}