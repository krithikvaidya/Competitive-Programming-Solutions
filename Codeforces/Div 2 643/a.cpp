#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

bool check(int a)
{
    while (a > 0)
    {
        if (a % 10 == 0)
            return false;
        a /= 10;
    }

    return true;
}

pair<int, int> min_dig(long long int a)
{
    int z = 9;
    int y = -1;
    while (a > 0)
    {
        if (a % 10 < z)
        {
            z = a % 10;
            if (z == 0)
                return make_pair(0, y);
        }
        if (a % 10 > y)
            y = a % 10;
        a /= 10;
    }

    return make_pair(z, y);
}

int max_dig(int a)
{
    int z = -1;
    while (a > 0)
    {
        if (a % 10 > z)
            z = a % 10;
        a /= 10;
    }

    return z;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        lli a, k;
        cin >> a >> k;

        lli j = 1ll;

        while (j++ < k)
        {
            pair <int, int> mind = min_dig(a);
            
            if (mind.first == 0)
                break;

            a += (long long)(mind.first * mind.second);
        }

        cout << a << "\n";

    }

}
