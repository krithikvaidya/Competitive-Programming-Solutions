#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ctr = 0;
    while(n > 0)
    {
        if(n&1)
            ctr++;
        n = n>>1;
    }
    cout<<ctr;
}
