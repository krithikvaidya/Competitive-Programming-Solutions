#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int DFS (vector<vector<int> > &adj_list, int node, vector<bool> &visited, int ht, vector<int> &parent, int par, vector<pair<long long int, int> > &max_hap)
{
    if (visited[node])
        return -1;

    parent[node] = par;
    visited[node] = true;
    ht++;

    if (adj_list[node].size() == 1 && node != 0)
        return 0;

    // if all nodes from 1 to this was tourist, then how much happ increase?

    int cur_wt = 0;
    long long int tot_hap_inc = 1;
    for (int adj: adj_list[node])
    {
        cur_wt += (1 + DFS (adj_list, adj, visited, ht, parent, node, max_hap));
    }

    tot_hap_inc = cur_wt * ht;
    max_hap.push_back(make_pair(tot_hap_inc, node)); 
    
    return cur_wt;
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
    vector<int> parent(n);
    parent[0] = -1;

    vector<pair<long long int, int> > max_hap;

    DFS (adj_list, src, visited, 0, parent, -1, max_hap);
    
    sort (max_hap.rbegin(), max_hap.rend());

    long long int thap = 0ll;
    vector<int> node_assigned(n);
    int n_tourist = n - k;

    for (int i = 0; i < max_hap.size(); i++)
    {
        while (i < max_hap.size() && node_assigned[i] == 1)
            i++;

        if (i == max_hap.size())
            break;
        
        int path_len = 0;
        // calculate path len to nearest node_assigned

        int cur_node = max_hap[i].second;
        int cur_node2 = cur_node;

        while (cur_node != -1 && node_assigned[cur_node] == 0)
        {
            path_len++;
            cur_node = parent[cur_node];
        }

        int path_len_top = path_len;
        while (cur_node != -1)
        {
            path_len_top++;
            cur_node = parent[cur_node];
        }

        if (path_len <= n_tourist)
        {
            cur_node = cur_node2;
            thap += ((max_hap[i].first / path_len_top) * path_len);

            while (cur_node != -1 && node_assigned[cur_node] == 0)
            {
                node_assigned[cur_node] = 1;
            }

            n_tourist -= path_len;

            // assign all of them.
            // add max_hap[cur_node] to total.
        }
        else
        {
            // do somet
            int climb = path_len - n_tourist;
            cur_node = cur_node2;

            while (climb--)
            {
                cur_node = parent[cur_node];
            }

            for (int j = i; j < n; j++)
            {
                if (max_hap[j].second == cur_node)
                {
                    int cl = 1;
                    int path_len_to_top = 0;
                    while (cur_node != -1)
                    {
                        path_len_to_top++;
                        cur_node = parent[cur_node];
                    }

                    thap += ((max_hap[i].first / path_len_top) * (path_len - n_tourist));
                    break;
                }
            }
            
            break;
        }
    }




    cout << thap;
}
