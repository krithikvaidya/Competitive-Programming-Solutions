#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);

        for (int j = 0; j < n; j++)
            cin >> a[j];

        for (int j = 0; j < n; j++)
            cin >> b[j];

        sort (a.begin(), a.end());
        sort (b.begin(), b.end());

        int sum = 0;

        int b_index = n - 1;
        int a_index = 0;
        
        while (k > 0 && a[a_index] < b[b_index])
        {
            k--;
            sum += b[b_index];
            a_index++;
            b_index--;
        }

        while (a_index < n)
        {
            sum += a[a_index];
            a_index++;
        }

        cout << sum << "\n";

    }

}
