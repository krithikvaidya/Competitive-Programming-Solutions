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
    int n;
    cin>>n;

    string str;
    string roots[n];

    for(int i = 0; i < n; i++)
    {
        bool count[26] = { false };
        cin>>str;

        for(char ch: str)
        {
            if(!count[ch-97])
            {
                roots[i].push_back(ch);
                count[ch-97] = true;
            }
        }

        sort(roots[i].begin(), roots[i].end());
    }

    sort(roots, roots + sizeof(roots)/sizeof(roots[0]));

    str = roots[0];
    int root_count = 1;

    for(int i = 1; i < n; i++)
    {
        if(roots[i] != str)
        {
            root_count++;
            str = roots[i];
        }
    }

    cout<<root_count;
}

