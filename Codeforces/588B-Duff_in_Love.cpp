#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll n, temp;
    cin>>n;
    temp = n;
    ll fin = 1ll;

    for(int i = 2; i <= sqrt(temp); i++)
    {
        if(n%i == 0)
        {
            fin *= i;
            while(n%i == 0)
                n/=i;
        }
    }

    if(n != 1)
        fin *= n;

    cout<<fin;
}
