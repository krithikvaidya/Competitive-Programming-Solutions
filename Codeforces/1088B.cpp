#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
        int n, k;

        cin >> n >> k;

        vector<int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        sort (a.begin(), a.end());
        int curr_sub = 0;

        for (int j = 0; j < n && k > 0; j++, k--)
        {
            while (j < n && a[j] - curr_sub == 0)
                j++;
            
            if (j == n)
                break;
            cout << (a[j] - curr_sub) << "\n";
            curr_sub = a[j];
        }

        while (k > 0)
        {
            cout << 0 << "\n";
            k--;
        }


    

}
