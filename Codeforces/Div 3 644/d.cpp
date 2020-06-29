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

        if (n <= k)
            {cout << 1 << "\n";
            continue;}

        int largest_fact = 1;

        for (int j = 2; j <= sqrt (n) && j <= k; j++)
        {
            bool flag = false;
            if (n % j == 0)
            {
                // cout << n << " " << j << "\n";
                
                if (n / j <= k)
                {
                    largest_fact = n/j;
                    break;
                }
                else
                {
                    largest_fact = j;
                }
                
                
            }

        }        

        cout << (n / largest_fact) << "\n";
    }

}
