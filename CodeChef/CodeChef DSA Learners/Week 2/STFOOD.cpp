#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int shopcount[n], customers[n], value[n];
        for (int j = 0; j < n; j++)
        {
            cin >> shopcount[j] >> customers[j] >> value[j];
        }

        int max_profit = INT_MIN;

        for (int j = 0; j < n; j++)
        {
            max_profit = max ((customers[j] / (shopcount[j] + 1)) * value[j], max_profit);
        }

        cout << max_profit << "\n";
    }
}