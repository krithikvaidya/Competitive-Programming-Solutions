#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int a[n];

    for(int i = 0; i < n; i++)
        cin>>a[i];

    cout<<(n+1)<<endl;
    long long val = 0ll;
    for(int i = n-1; i >= 0; i--)
    {
        a[i] += val;
        for(int j = 0; j < INT_MAX; j++)
        {
            if(a[i] <= (n+1)*j + i+1)
            {
                val += (n+1)*j + i+1 - a[i];
                cout<<"1 "<<(i+1)<<" "<<((n+1)*j + i+1 - a[i])<<"\n";
                break;
            }
        }
    }
    cout<<"2 "<<(n)<<" "<<(n+1);
}
