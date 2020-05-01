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

        long long curr_sum = 0ll;
        long long exp_sum = ((long long)k * (k + 1)) / 2;

        map<int, int> occ_count;

        vector<int> a(n);
        
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];

            if (j < k - 1)
            {
                occ_count[a[j]]++;
                if (occ_count[a[j]] == 1)
                {
                    curr_sum += a[j];
                }
            }

        }

        // cout << "\nexp_sum: " << exp_sum << " curr_sum: " << curr_sum << "\n";
        int lwr_index = 0, upr_index = k - 1;
        int max_elem = k - 1;
        int curr_elem = k - 1;
        
        while (upr_index < n)
        {
            if (curr_sum == exp_sum)
            {
                // cout << "\nnever1\n";
                --occ_count[a[lwr_index]];
                if (occ_count[a[lwr_index]] == 0)
                    curr_sum -= a[lwr_index];

                lwr_index++;
                curr_elem--;
                continue;
            }

            ++occ_count[a[upr_index]];
            // cout << "\nupr_index: " << upr_index << "\nocc_count: " << occ_count[a[upr_index]] << "\n";
            if (occ_count[a[upr_index]] == 1)
            {
                // cout << "\nnever2\n";
                curr_sum += a[upr_index];
                curr_elem++;

                if (curr_sum != exp_sum)
                    max_elem = max (max_elem, curr_elem);
                
                    upr_index++;
                continue;
            }
            
            
            upr_index++;
            curr_elem++;

            // cout << "upr_index: " << upr_index << " curr_elem: " << curr_elem << "\n";
            max_elem = max (max_elem, curr_elem);
            
        }

        cout << max_elem << "\n";
        
    }

}
