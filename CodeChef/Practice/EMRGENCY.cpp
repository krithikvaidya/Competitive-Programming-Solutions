#include <bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
using namespace std;
int main()
{
    int T;
    cin>>T;
    int answers[T];
    REP(i, T)
    {
        int n, m, c1, c2, total_price = 0;
        cin>>n>>m;
        int cost[n + 1];
        vector<int> cities[n + 1];
        for(int j = 1; j <= n; j++)
        {
             scanf("%d", &cost[j]);
        }
        REP(j, m)
        {
            scanf("%d %d", &c1, &c2);
            cities[c1].push_back(c2);
            cities[c2].push_back(c1);
        }
        bool visited[n + 1] = { false };
        for(int j = 1; j <= n; j++)
        {
            if(visited[j])
                continue;
            visited[j] = true;
            int lprice = cost[j];
            stack<int> to_process;
            to_process.push(j);
            while(!to_process.empty())
            {
                // Pop a vertex from stack and print it
                int s = to_process.top();
                to_process.pop();
                // Stack may contain same vertex twice. So
                // we need to print the popped item only
                // if it is not visited.
                if (!visited[s])
                {
                    visited[s] = true;
                    if(cost[s] < lprice)
                        lprice = cost[s];
                }
                // Get all adjacent vertices of the popped vertex s
                // If a adjacent has not been visited, then puah it
                // to the stack.
                for (int k : cities[s])
                    if (!visited[k])
                        to_process.push(k);
            }
            total_price += lprice;
        }
        answers[i] = total_price;
    }
    for(int i = 0; i < T; i++)
        cout<<answers[i]<<"\n";
}
