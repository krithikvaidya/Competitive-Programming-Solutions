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
        long long int n, a, b, k;
        cin >> n >> a >> b >> k;

        long long GCD = __gcd (a, b);
        long long LCM = (a * b) / GCD;
        if ((n/a) + (n/b) - 2 * (n/(LCM)) >= k)
            cout << "Win\n";
        else
        {
            cout << "Lose\n";
        }
        

    }

}
