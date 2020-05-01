#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

vector<pair<int, int> > weights;
long long int tot_hap;

int DFS (vector<vector<int> > &adj_list, int node, vector<bool> &visited)
{
    if (visited[node])
        return -1;

    visited[node] = true;

    if (adj_list[node].size() == 1)
    {
        weights.push_back(make_pair(0, node));
        return 0;
    }

    int cur_wt = 0;
    for (int adj: adj_list[node])
    {
        cur_wt += 1 + DFS (adj_list, adj, visited);
    }

    weights.push_back(make_pair(cur_wt, node));

    return cur_wt;
}

void DFS2 (vector<vector<int> > &adj_list, vector<int> &types, int node, vector<bool> &visited, int ht)
{
    if (visited[node])
        return;

    visited[node] = true;

    if (types[node] != 1)
    {
        ht++;
        for (int adj: adj_list[node])
        {
            DFS2 (adj_list, types, adj, visited, ht);
        }
    }
    else
    {
        tot_hap += ht;
        
        for (int adj: adj_list[node])
        {
            DFS2 (adj_list, types, adj, visited, ht);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int n1, n2;
    vector<vector<int> > adj_list(n);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> n1 >> n2;
        adj_list[n1 - 1].push_back(n2 - 1);
        adj_list[n2 - 1].push_back(n1 - 1);
    }

    int src = 0;

    vector<bool> visited(n);

    DFS (adj_list, src, visited);

    //for (auto a: weights)
     //   cout << a.first << " " << a.second << "\n";

    sort (weights.begin(), weights.end());

    vector<int> types(n);

    for (int i = 0; i < k; i++)
    {
        types[weights[i].second] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << types[i] << " ";
    }
    cout << "\n";

    vector<bool> visited2(n);

    DFS2 (adj_list, types, 0, visited2, 1);

    cout << tot_hap;
}
