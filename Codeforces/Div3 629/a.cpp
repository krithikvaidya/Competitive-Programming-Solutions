#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int a, b, div;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;

        if (a <= b)
        {
            cout << (b - a) << "\n";
            continue;
        }

        if (a % b == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        
        int div = (a / b) + 1;
        div = (div * b)  - a;
        cout << div << "\n";
    }
}