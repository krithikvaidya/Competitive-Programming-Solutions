#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    cin>>n>>k;
    long long n2 = n;

    long long max_pwr = 0ll, sum = 0ll;
    while(n2 != 0)
    {
        max_pwr += 1;
        n2 = n2>>1;
    }

    if(k == 1)
    {
        cout<<n;
    }
    else
    {
        sum = ((long long)pow(2, max_pwr)) - 1;
        cout<<sum;
    }
}
