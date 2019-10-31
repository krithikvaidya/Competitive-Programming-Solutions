#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        int p[n + 5];
        p[0] = p[1] = p[2] = p[3] = p[4] = INT_MAX;
        int count = 0;
        for(int j = 5; j < n + 5; j++)
        {
            cin >> p[j];
            if(p[j] < p[j - 1] && p[j] < p[j - 2] && p[j] < p[j - 3] && p[j] < p[j - 4] && p[j] < p[j - 5])
                count++;
        }
        cout << count << "\n";
    }
}
