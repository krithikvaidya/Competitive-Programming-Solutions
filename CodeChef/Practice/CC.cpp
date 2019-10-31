#include <bits/stdc++.h>
using namespace std;
void dfs(int root, vector<int> graph[], bool visited[])
{
    if(visited[root])
        return;
    visited[root] = true;
    for(int node: graph[root])
        dfs(node, graph, visited);
}
int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        int n, e;
        cin>>n>>e;
        vector<int> graph[n];
        int a, b;
        for(int j = 0; j < e; j++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int cc = 0;
        bool visited[n] = { false };
        for(int j = 0; j < n; j++)
        {
            if(!visited[j])
            {
                cc++;
                dfs(j, graph, visited);
            }
        }
        cout<<cc<<endl;
    }
}
