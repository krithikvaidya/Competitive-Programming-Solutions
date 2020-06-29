// Prime Factorization using Sieve O(log n) for multiple queries

#include <bits/stdc++.h>

#define lli long long int
#define ld long double

#define MAX 100000000

using namespace std;

void sieve (vector<int> &spf)
{
    for (int i = 2; i < MAX; i++)
    {
        if (spf[i] == -1)
        {
            for (int j = i * i; j < MAX; j += i)
                spf[j] = spf[j] == -1 ? i: spf[j];
        }
    }
}

void calc_prime_factorization (vector <int> &spf, int val)
{
    while (val > 1)
    {
        cout << spf[val] << " ";
        val /= spf[val];
    }

    cout << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector <int> spf(MAX);

    fill (spf.begin(), spf.end(), -1);

    sieve (spf);

    calc_prime_factorization(spf, 2);
    calc_prime_factorization(spf, 10);
    calc_prime_factorization(spf, 96);


}
