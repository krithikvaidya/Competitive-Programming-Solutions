#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

long double d2r(long double d) {
  const auto PI = std::acos((long double)(-1L));
  return (d / 180.000000000L) * PI;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ld n;
        cin >> n;

        n *= 2.0000000000L;

        if (n == 4)
        {    cout << 1 << "\n"; continue; }

        ld angle = ((n - 2L) * 180.000000000L) / n;
        ld curr_angle = (angle / 2.0000000000L);

        cout << std::fixed << std::setprecision(6) << tan (d2r(curr_angle)) << "\n";
        
    }

}
