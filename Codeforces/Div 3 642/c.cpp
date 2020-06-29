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
        lli n;
        cin >> n;
        lli sum = 0ll;

        for (long long int j = 1ll; j <= n / 2; j++)
            sum += j * j;

        sum *= 8;

        cout << sum << "\n";

    }

}
