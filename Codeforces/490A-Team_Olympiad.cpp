#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> skill1;
    vector<int> skill2;
    vector<int> skill3;

    int temp;
    for(int i = 1; i <= n; i++)
    {
        cin>>temp;
        if(temp == 1)
            skill1.push_back(i);
        else if(temp == 2)
            skill2.push_back(i);
        else
            skill3.push_back(i);
    }

    int max_teams = min({skill1.size(), skill2.size(), skill3.size()});
    if(max_teams == 0)
        cout<<0;
    else
    {
        cout<<max_teams<<"\n";
        for(int i = 0; i < max_teams; i++)
        {
            cout<<skill1[i]<<" "<<skill2[i]<<" "<<skill3[i]<<"\n";
        }
    }

}
