#include <bits/stdc++.h>

#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define fast ios::sync_with_stdio(0); cin.tie(0);

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

using namespace std;

int main()
{
    fast
    int n;
    cin>>n;

    int s[n];
    for(int i = 0; i < n; i++)
        cin>>s[i];

    int c[n];
    for(int i = 0; i < n; i++)
        cin>>c[i];


    int costs2[n];
    for(int i = 0; i < n; i++)
        costs2[i] = -1;

    int min;

    for(int i = 1; i < n; i++)
    {
        min = INT_MAX;
        for(int j = i - 1; j >= 0; j--)
        {
            if(s[j] < s[i] && c[j] < min)
                min = c[j];
        }
        if(min != INT_MAX)
            costs2[i] = min + c[i];
        else
            costs2[i] = -1;
    }

    int gmin = INT_MAX;

    for(int i = 2; i < n; i++)
    {
        min = INT_MAX;
        for(int j = i - 1; j >= 0; j--)
        {
            if(s[j] < s[i] && costs2[j] != -1 && costs2[j] < min)
                min = costs2[j];
        }
        if(min != INT_MAX)
        {
            if(min + c[i] < gmin)
                gmin = min + c[i];
        }
    }
    if(gmin != INT_MAX)
    cout<<gmin;
    else
        cout<<-1;
}

