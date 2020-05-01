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
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        if (n * (a - b) > c + d || n * (a + b) < c - d)
            cout << "No\n";
        else
        {
            cout << "Yes\n";
        }
    
    }
}
