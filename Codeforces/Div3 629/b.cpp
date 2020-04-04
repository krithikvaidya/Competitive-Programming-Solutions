#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t, last, n, k;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        last = n - 1;
        
        string permutation(n, 'a');
        
        for (int i = n - 2; i >= 0; i--) 
        {
            
            if (k <= last - i) 
            {
                
                permutation[i] = 'b';
                permutation[n - k] = 'b';
                break;
                
            }
            
            k -= (last - i);
        }
        
        cout << permutation << "\n";
        
    }
}