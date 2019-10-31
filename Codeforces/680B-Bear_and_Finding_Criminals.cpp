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
    int n, a;
    cin>>n>>a;

    int cr[n + 1];
    for(int i = 1; i <= n; i++)
        cin>>cr[i];

    int caught = 0;

    if(cr[a] == 1)
        caught++;

    int i = 1;

    while(a - i > 0 && a + i <= n)
    {
        if(cr[a - i] + cr[a + i] == 2)
            caught+=2;
        i++;
    }

    while(a - i != 0)
    {
        if(cr[a - i] != 0)
            caught++;
        i++;
    }

    while(a + i <= n)
    {
        if(cr[a + i] != 0)
        {

            caught++;
        }
        i++;
    }

    cout<<caught;
}

