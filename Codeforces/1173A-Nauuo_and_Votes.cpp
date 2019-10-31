#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z;
    cin>>x>>y>>z;

    if(x == y && z == 0)
        cout<<"0";
    else if(abs(x-y) <= z)
        cout<<"?";
    else
    {
        if(x > y)
            cout<<"+";
        else if(x <= y)
            cout<<"-";
    }
}
