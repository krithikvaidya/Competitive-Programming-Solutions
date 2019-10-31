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
    int q;
    cin>>q;

    long long piles[3];
    for(int i = 0; i < q; i++)
    {
        cin>>piles[0]>>piles[1]>>piles[2];
        sort(piles, piles + 3);

        long long al = piles[0];
        long long bob = piles[1];
        long long x = (piles[2] - abs(al - bob))/2;

        cout<<(max(al, bob) + x)<<"\n";
    }
}

