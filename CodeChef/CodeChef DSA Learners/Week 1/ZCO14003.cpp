#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> budget(n);
    for (int i = 0; i < n; i++)
        cin >> budget[i];

    sort (budget.rbegin(), budget.rend());

    long long max = 0ll;
    int curr_budget;

    for (int i = 0; i < n; i++)
    {
        curr_budget = budget[i];
        if ((long long)curr_budget * (long long)(i + 1) > max)
            max = (long long)curr_budget * (long long)(i + 1);
    }

    cout << max;
}