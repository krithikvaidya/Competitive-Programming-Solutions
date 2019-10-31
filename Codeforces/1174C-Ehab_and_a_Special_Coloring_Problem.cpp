#include <bits/stdc++.h>

using namespace std;

vector<bool> is_prime;

void sieve()
{
    for(int i = 0; i < 100001; i++)
        is_prime.push_back(true);

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < 100001; i++)
    {
        if(is_prime[i])
        {
            for(int j = i * 2; j < 100001; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    sieve();
    int n;
    cin>>n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> values;
    int j;
    values.push_back(2);
    cout<<1<<" ";
    for(int i = 3; i <= n; i++)
    {
        if(is_prime[i])
            goto label;
        for(j = 0; j < values.size(); j++)
        {
            if(__gcd(values[j], i) != 1)
            {
                cout<<(j+1)<<" ";
                break;
            }
        }

        if(j==values.size())
        {
            label:
            values.push_back(i);
            cout<<(values.size())<<" ";
        }
    }
}
