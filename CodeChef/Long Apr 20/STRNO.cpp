#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

std::pair<int, int> primeFactors(int n)  
{  
    int count = 0, dist_count = 0;  
    while (n % 2 == 0)  
    {  
        count++;
        dist_count = 1;
        n = n/2;  
    }  
  
    bool flag;
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {   
        flag = true;
        while (n % i == 0)  
        {  
            if (flag)
            {
                dist_count++;
                flag = false;
            }
            count++;  
            n = n/i;  
        }  
    }  

    if (n > 2)  
    {
        count++;
        dist_count++;
    }

    return make_pair(count, dist_count);  
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x, k;
        cin >> x >> k;

        if (k == 1 && x > 1)
        {
            cout << 1 << "\n";
            continue;
        }

        if (x == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        
        // don't forget 1 as factor
        if (k >= 30 || x <= k || pow(2, k) > x)
        {
            cout << 0 << "\n";
            continue;
        }

        std::pair<int, int> factors = primeFactors(x);

        // cout << endl << factors.first << endl << factors.second << endl;

        if (factors.first < k)
        {
            cout << 0 << "\n";
        }
        else
        {

            cout << 1 << "\n";
            
        }
        
        
        /**
        int pwr = 1;

        for (int j = 1; j <= k; j++)
            pwr *= 2;

        int hmm = x - 1;
        if (hmm % (pwr - 1) == 0)
            cout << 1 << "\n";
        else
        {
            cout << 0 << "\n";
        }
        */
        
    }   

}