#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

vector<pair <int, int> > edge_weights;
int leaf_index;

bool DFS (vector<vector<pair<int, int> > > &adj_list, int node, vector<bool> &visited)
{
    if (visited[node])
        return false;
    
    visited[node] = true;

    if (adj_list[node].size() == 1)
        return true;

    for (auto adj: adj_list[node])
    {
        if (DFS(adj_list, adj.second, visited))
        {
            edge_weights.push_back(make_pair(adj.first, leaf_index));
            leaf_index++;
        }
    }

    return false;
}


int main()
{
    //cout << "OK";
    edge_weights.clear();
    leaf_index = 0;
    int n;
    cin >> n;

    vector<vector<pair<int, int> > > adj_list(n);
    int node1, node2;
    //cout << "OK";
    for (int j = 0; j < n - 1; j++)
    {
        cin >> node1 >> node2;
        adj_list[node1 - 1].push_back(make_pair(j, node2 - 1));
        adj_list[node2 - 1].push_back(make_pair(j, node1 - 1));
    }

    vector<bool> visited(n);
    //cout << "OK";

    if (n == 2)
        {cout << 0 << "\n"; return 0;}

    int init = 0;

    while (adj_list[init].size() == 1)
        init++;

    DFS (adj_list, init, visited);

    sort (edge_weights.begin(), edge_weights.end());

    int outer_index = leaf_index;
    int inner_index = 0;

    
    for (int j = 0; j < n - 1; j++)
    {
        if (edge_weights.size() > 0 && inner_index < edge_weights.size() && j == edge_weights[inner_index].first)
        {
            cout << edge_weights[inner_index].second << "\n";
            inner_index++;
        }
        else
        {
            cout << outer_index << "\n";
            outer_index++;
        }
    }



}
