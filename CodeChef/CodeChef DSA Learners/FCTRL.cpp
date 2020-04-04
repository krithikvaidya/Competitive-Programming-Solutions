#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, no_of_fives = 0;
        cin >> n;

        if (n <= 4)
        {
            cout << "0" << "\n";
            continue;
        }

        long long pow_5 = 5;
        while (n / pow_5 > 0)
        {
            no_of_fives += n / pow_5;
            pow_5 *= 5;
        }

        cout << no_of_fives << "\n";
    }
}