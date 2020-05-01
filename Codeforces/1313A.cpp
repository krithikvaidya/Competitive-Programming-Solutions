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
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];

        sort(a.rbegin(), a.rend());

        int ans = 0;
        if (a[2] >= 1)
            ans = 3;
        
        else if (a[1] >= 1)
        {
            ans = 2;
        }

        else if (a[0] >= 1)
            ans = 1;
        
        a[0]--;
        a[1]--;
        a[2]--;

        if (a[2] >= 2)
        {
            ans += 3;
            a[0]-=2;
            a[1]-=2;
            a[2]-=2;

            if (a[2] >= 1)
                ans++;
        }
        else if (a[2] == 1)
        {
            if (a[1] >= 2 && a[0] >= 2)
                ans += 2;
            else if (a[1] == 1 && a[0] >= 2)
                ans += 2;
            else if (a[1] == 1 && a[0] == 1)
                ans += 1;
        }
        else
        {
            if (a[1] >= 1)
                ans += 1;
        }

        

        cout << ans << "\n";
        


    }

}
