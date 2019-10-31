#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int n, m, edge_sum, a, b, s;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> m;
        // Construct adjacency list
        vector<int> adjList[n];
        for(int j = 0; j < m; j++)
        {
            cin >> a >> b;
            adjList[a - 1].push_back(b - 1);
            adjList[b - 1].push_back(a - 1);
        }
        int belongs[n] = { 0 };
        if(!(m & 1))
        {
            cout << "1" << "\n";
            for(int j = 0; j < n; j++)
                cout << "1" << " ";
            cout << "\n";
            continue;
        }
        bool visited[n] = { false };
        int flag = 1;
        vector<vector<int> > components;
        int flag2 = 1;
        for(int j = 0; j < n; j++)
        {
            if(adjList[j].size() & 1)
            {
                belongs[j] = 1;
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            for(int j = 0; j < n; j++)
            {
                if(adjList[j].size() > 0)
                {
                    belongs[j] = 1;
                    belongs[adjList[j][0]] = 2;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout << "2" << "\n";
        }
        else
        {
            cout << "3" << "\n";
        }
        for(int j = 0; j < n; j++)
            cout << (belongs[j] + 1) << " ";
        cout << "\n";
    }
}
