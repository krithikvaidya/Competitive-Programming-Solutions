#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int g;
        cin >> g;

        for (int j = 0; j < g; j++)
        {
            int i, n, q;
            cin >> i >> n >> q;

            if (n & 1 && i != q)
                cout << ((n / 2) + 1) << "\n";

            else
                cout << (n / 2) << "\n";
        }
        
    }
}