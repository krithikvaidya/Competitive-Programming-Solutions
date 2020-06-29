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

        ld angle = ((n - 2L) * 180.000000000L) / n;
        ld curr_angle = (angle / 2.0000000000L);

        //cout << curr_angle << "\n";

        ld ht = (1.000000000L / (2.000000000L * tan (d2r(180.000000000L / n))));
        //cout << ht << "\n";
        ht /= sin (d2r (curr_angle));
        //cout << ht << "\n";
        ht *= 2;
        cout << std::fixed << std::setprecision(6) << ht << "\n";
        
    }

}
