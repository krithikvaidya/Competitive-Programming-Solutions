#include <bits/stdc++.h>

using namespace std;

void primeFactors(int n, map <int, int> &factor_powers)  
{
    int fc_count = 0;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        fc_count++;  
        n = n/2;  
    }  

    factor_powers[2] = max (fc_count, factor_powers[2]);
    
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        fc_count = 0;
        while (n % i == 0)  
        {  
            fc_count++;
            n = n/i;  
        }
        
        factor_powers[i] = max (fc_count, factor_powers[i]);

    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
    {
        factor_powers[n] = max (1, factor_powers[n]);
    }
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int n, m;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int a[n];
        
        map <int, int> factor_powers;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            primeFactors(a[j], factor_powers);
        }

        int max_inc = 1, curr_inc;

        for (int j = 1; j <= m; j++)
        {
            curr_inc = 1;
            map <int, int> factor_powers2;
            primeFactors(j, factor_powers2);

            for (auto i : factor_powers2) 
            {
                curr_inc = max (curr_inc, int (pow (i.first, (i.second - factor_powers[i.first])) * curr_inc));
            }

            if (curr_inc > max_inc)
                max_inc = curr_inc;
        }

        cout << curr_inc << "\n";

    }
}