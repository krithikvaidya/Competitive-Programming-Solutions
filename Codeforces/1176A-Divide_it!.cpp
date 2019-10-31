#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin>>n;

    ll q[n];
    ll op_count[n] = { 0 };

    for(int i = 0; i < n; i++)
    {
        cin>>q[i];

        while(q[i] % 5 == 0)
        {
            q[i] = 4 * (q[i] / 5);
            op_count[i]++;
        }

        while(q[i] % 3 == 0)
        {
            q[i] = 2 * (q[i] / 3);
            op_count[i]++;
        }

        while(q[i] % 2 == 0)
        {
            q[i] = q[i] / 2;
            op_count[i]++;
        }

        if(q[i] != 1)
            op_count[i] = -1;
    }

    for(int i = 0; i < n; i++)
        cout<<op_count[i]<<endl;
}
