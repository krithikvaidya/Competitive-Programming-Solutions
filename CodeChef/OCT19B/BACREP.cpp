#include <bits/stdc++.h>
using namespace std;
int n;
bool isLeaf(vector<vector<int> > adjList, int vertex)
{
    if(n == 1)
        return true;
    if(adjList[vertex].size() == 1 && (vertex != 0))
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q, a, b;
    cin >> n >> q;
    vector<vector<int> > adjList(n);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }
    int parent[n];
    for(int i = 0; i < n; i++)
        parent[i] = -1;
    queue<int> to_process;
    to_process.push(0);
    int s;
    bool visited[n] = { false };
    while(!to_process.empty())
    {
        s = to_process.front();
        to_process.pop();
        if(visited[s])
            continue;
        visited[s] = true;
        for(int child: adjList[s])
        {
            if(!visited[child])
            {
                parent[child] = s;
                to_process.push(child);
            }
        }
    }
    vector<map<int, long long int> > bacteria(n);
    vector<vector<pair<int, int> > > added_bacteria(n);
    long long int c;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        added_bacteria[i].push_back(make_pair(0, c));
    }
    bool checked[n] = { false };
    // store the queries of the second type.
    vector<pair<int, int> > queries;
    char ch;
    int v, k;
    cin.ignore();
    for(int i = 0; i < q; i++)
    {
        cin >> ch;
        // cout << "CH: " << ch << "\n";
        // cout << "\n\nch: " << ch << "\n\n";
        if(ch == '+')
        {
            // cout << "HM2M";
            cin >> v >> k;
            added_bacteria[v - 1].push_back(make_pair(i + 1, k));
        }
        else
        {
            // cout << "AA";
            cin >> v;
            // cout << "AA";
            // cout << "v: " << v << "\n";
            queries.push_back(make_pair(i + 1, v - 1));
            // cout << "v: " << v << "\n";
        }
        //cout << "i: " << i << "\n";
    }
    // cout << "hmm";
    for(auto bact: added_bacteria[0])
        bacteria[0][bact.first] = (long long int)bact.second;
    // cout << "hmm";
    checked[0] = true;
    // for every query, if that node is checked, check if its leaf or non leaf
    // and print accordingly.
    // if not checked, clamber up the tree by using parent array till you get a visited one.
    // set the child  node's map to that thing and set the offset to  that thing + 1.
    // then sets
    int temp, i;
    for(auto query: queries)
    {
        if(query.second == 0)
        {
            if(isLeaf(adjList, 0))
            {
                auto it3 = bacteria[0].upper_bound(query.first);
                it3--;
                cout << (it3 -> second) << "\n";
            }
            else
            {
                cout << bacteria[0][query.first] << "\n";
            }
            continue;
        }
        // cout << "hmm";
        if(checked[query.second])
        {
            if(!isLeaf(adjList, query.second))
                cout << bacteria[query.second][query.first] << "\n";
            else
            {
                auto it3 = bacteria[query.second].upper_bound(query.first);
                it3--;
                cout << (it3 -> second) << "\n";
            }
            continue;
        }
        // cout << "hmm";
        vector<int> path(n);
        i = 0;
        temp = query.second;
        while(!checked[temp])
        {
            path[i] = temp;
            i++;
            temp = parent[temp];
        }
        i--;
        // cout << "hmm3";
        for(auto it = bacteria[parent[path[i]]].begin(); it != bacteria[parent[path[i]]].end(); it++)
            bacteria[path[i]][(it -> first) + 1] = it -> second;
        // cout << "hmm4";
        checked[path[i]] = true;
        int elem = path[i];
        // cout << "hmm";
        for(auto bact: added_bacteria[elem])
        {
            bacteria[elem][bact.first] += (long long int)bact.second;
        }
        // cout << "hmm";
        i--;
        int parentelem;
        while(i >= 0)
        {
            elem = path[i];
            parentelem = parent[path[i]];
            for(auto it = bacteria[parentelem].begin(); it != bacteria[parentelem].end(); it++)
            {
                bacteria[elem][(it -> first) + 1] = it -> second;
            }
            for(auto bact: added_bacteria[elem])
            {
                bacteria[elem][bact.first] += (long long int)bact.second;
            }
            checked[elem] = true;
            i--;
        }
        if(isLeaf(adjList, query.second))
        {
            auto End = bacteria[query.second].end();
            auto it1 = bacteria[query.second].begin();
            auto it2 = bacteria[query.second].begin();
            it2++;
            while(it2 != End)
            {
                bacteria[query.second][((it2) -> first)] += (long long int)(it1 -> second);
                it1++;
                it2++;
            }
            auto it3 = bacteria[query.second].upper_bound(query.first);
            it3--;
            cout << (it3 -> second) << "\n";
        }
        else
            cout << bacteria[query.second][query.first] << "\n";
    }
}
