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
    int T;
    cin>>T;
    ll answers[T];
    int n;
    char ch;
    ll ctr;
    for(int i = 0; i < T; i++)
    {
        cin>>n;
        cin.ignore();
        ctr = 0;
        for(int j = 0; j < n; j++)
        {
            cin>>ch;
            if(ch == '1')
                ctr++;
        }
        answers[i] = ((ctr) * (ctr - 1ll))/2ll + ctr;
    }
    for(int i = 0; i < T; i++)
        cout<<answers[i]<<"\n";
}
