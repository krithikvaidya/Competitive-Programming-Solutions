#include <bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
using namespace std;
void dfs(ll node, vector<ll> graph[], bool visited[], int* frncount)
{
    if(visited[node])
        return;
    visited[node] = true;
    *frncount = *frncount + 1;
    for(ll nodes: graph[node])
        dfs(nodes, graph, visited, frncount);
}
int main()
{
    FAST
    int t;
    cin>>t;
    string answers[t];
    for(int o = 0; o < t; o++)
    {
        int n, m;
        cin>>n>>m;
        vector<ll> employees[n + 1];
        int a, b;
        for(int i = 0; i < m; i++)
        {
            cin>>a>>b;
            employees[a].push_back(b);
            employees[b].push_back(a);
        }
        ll combs = 1ll;
        ll routes = 0ll;
        //DFS to find components
        bool visited[n + 1] = { false };
        int frncount;
        for(ll i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                frncount = 0;
                dfs(i, employees, visited, &frncount);
                routes = (routes + 1) % 1000000007;
                combs = ((combs % 1000000007)*(frncount % 1000000007)) % 1000000007;
            }
        }
        answers[o] = (to_string(routes) + " " + to_string(combs));
    }
    for(string answer: answers)
        cout<<answer<<endl;
}
