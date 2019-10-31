#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b + c == 1)
        {
            cout << "NO\n";
            continue;
        }
        if((a * 1 + b * 2 + c * 3) & 1)
        {
            cout << "NO\n";
            continue;
        }
        if(a + b + c == a || a + b + c == b || a + b + c == c)
        {
            if((b) & 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        if(a == 0)
        {
            if(b == 1)
            {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
            continue;
        }
        if(b == 0)
        {
            if(a == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        if(c == 0)
        {
            if(a == 1 && b == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        cout << "YES\n";
        continue;
    }
}
