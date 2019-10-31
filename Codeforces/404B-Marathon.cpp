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
    long double a, d;
    cin>>a>>d;

    ll n;
    cin>>n;

    long double dist = 0;
    cout<<setprecision(5);

    for(ll i = 1; i <= n; i++)
    {
        dist += d;
        if(dist >= 4 * a)
            dist = fmod(dist, 4 * a);

        if(dist <= a)
        {
            cout<<dist<<" "<<0;
        }
        else if(dist > a && dist <= 2 * a)
        {
            cout<<a<<" "<<dist - a;
        }
        else if(dist > 2*a && dist <= 3 * a)
        {
            cout<<(a - (dist-2*a))<<" "<<a;
        }
        else
        {
            cout<<0<<" "<<(a - (dist-3*a));
        }
        cout<<"\n";
    }
}

