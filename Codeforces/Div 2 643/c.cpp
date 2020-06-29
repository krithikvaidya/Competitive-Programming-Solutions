#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == b == c == d)
    {
        cout << 1 << "\n";
        return 0;
    }

    int e = a;
    a = 1;
    b -= (e - 1);
    c -= (e - 1);
    d -= (e - 1);
    //cout << a << b << c << d << "\n";
    lli term_count = 0ll;
    int k = 1;

    int r = c;

    for (int j = (b - a + 1); j >= 1; j--)
    {
        //cout  << j << " " << k << "\n";
        term_count += (long long)(j * k) * ();
        k++;

        if (k > (c - b + 1))
            break;

        r++;
        if (r > d)
            break;
    }

    cout << term_count << "\n";

}
