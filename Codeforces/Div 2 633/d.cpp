#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

bool visited[100001];
bool odd_flag;
int uniq;
int leafcount;

pair<int, int> dfs(vector<int> adj[], int s) 
{
    if (visited[s]) 
        return make_pair(0, 0);

    visited[s] = true;

    if (adj[s].size() == 1)
    {
        return 1;
    }

    int curr_leafcount = 0;

    for (auto u: adj[s]) 
    {
        curr_leafcount += dfs(adj, u);
    }

    if (curr_leafcount >= 2)
        leafcount += curr_leafcount - 1;
    
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    for (int j = 0; j < 100001; j++)
        visited[j] = false;

    odd_flag = false;
    uniq = 0;
    leafcount = 0;

    int n;
    cin >> n;

    vector<int> adj[n];
    int node1, node2;

    for (int j = 0; j < n - 1; j++)
    {
        cin >> node1 >> node2;
        adj[node1 - 1].push_back(node2 - 1);
        adj[node2 - 1].push_back(node1 - 1);
    }

    int j;
    for (j = 0; j < n; j++)
    {
        if (adj[j].size() != 1)
            break;
    }

    int sa = dfs (adj, j);
    if (sa > 2)
        leafcount += sa - 1;

    cout << (n - 1 - leafcount) << "\n";

}
