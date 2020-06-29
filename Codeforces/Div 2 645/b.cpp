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
        int n;
        cin >> n;

        vector <int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        sort (a.begin(), a.end());

        int curr_grannies_count = 0;
        int curr_reqd_grannies_count = 0;
        int curr_increment = 0;
        int j = 0;
        int count = 1;
        for (j = 0; j < n; j++)
        {
            curr_grannies_count++;
            curr_increment++;
            if (a[j] <= curr_grannies_count)
            {
                count += curr_increment;
                curr_increment = 0;
            }
            
        }  

        cout << count << "\n";
    }

}
