# include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<string> answers;
    for(int i = 0; i < t; i++)
    {
        int q;
        cin>>q;
        vector<int> Set;
        int x[q];
        bool app[100001] = { false };
        for(int j = 0; j < q; j++)
        {
            vector<int> addtoset;
            int val, e=0, o=0;
            cin>>x[j];
            if(app[x[j]] == false)
            {
                app[x[j]] = true;
                Set.push_back(x[j]);
            }
            if(__builtin_popcount(x[j])&1)
                o++;
            else
                e++;
            for(auto it = Set.begin(); it != Set.end(); it++)
            {
                if(*it == x[j])
                    continue;
                if(__builtin_popcount(*it)&1)
                    o++;
                else
                    e++;
                val = (*it)^x[j];
                if(find(addtoset.begin(), addtoset.end(), val) == addtoset.end())
                {
                    addtoset.push_back(val);
                    if(!app[val])
                    {
                        if(__builtin_popcount(val)&1)
                            o++;
                        else
                            e++;
                    }
                }
            }
            for(int g: addtoset)
            {
                if(app[g] == false)
                {
                    Set.push_back(g);
                    app[g] = true;
                }
            }
            answers.push_back(to_string(e) + " " + to_string(o));
        }
    }
    for(string ans: answers)
        cout<<ans<<endl;
}
