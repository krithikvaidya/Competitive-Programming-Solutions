#include <bits/stdc++.h>
using namespace std;
bool friend_of(vector<int> student, int stu_num)
{
    for(int i = 0; i < student.size(); i++)
        if(student[i] == stu_num)
            return true;
    return false;
}
int main()
{
    int t;
    cin>>t;
    int answers[t];
    for(int i = 0; i < t; i++)
    {
        int n, s, f;
        cin>>n>>s>>f;
        int threat = 0, f1, f2, temp = 0, flag = 0;
        vector<int> graph[n + 1];
        for(int j = 0; j < f; j++)
        {
            cin>>f1>>f2;
            if(friend_of(graph[f1], f2))
                continue;
            graph[f1].push_back(f2);
            graph[f2].push_back(f1);
            for(int k = 0; k < graph[f1].size(); k++)
            {
                if((!friend_of(graph[f2], graph[f1][k])) && graph[f1][k] != f2)
                    graph[f2].push_back(graph[f1][k]);
            }
            for(int k = 0; k < graph[f2].size(); k++)
            {
                if((!friend_of(graph[f1], graph[f2][k])) && graph[f2][k] != f1)
                    graph[f1].push_back(graph[f2][k]);
            }
            for(int k = 0; k < graph[f1].size(); k++)
            {
                if(graph[f1][k] != f2)
                {
                    if(!friend_of(graph[graph[f1][k]], f2))
                        graph[graph[f1][k]].push_back(f2);
                }
            }
            for(int k = 0; k < graph[f2].size(); k++)
            {
                if(graph[f2][k] != f1)
                {
                    if(!friend_of(graph[graph[f2][k]], f1))
                        graph[graph[f2][k]].push_back(f1);
                }
            }
        }
        /**for(int j = 1; j <= n; j++)
        {
            cout<<j<<" -> ";
            for(int k = 0; k < graph[j].size(); k++)
                cout<<graph[j][k]<<" -> ";
            cout<<endl;
        }*/
        for(int j = 1; j <= n; j++)
        {
            if(j != s && !friend_of(graph[j], s))
            {
                flag = 1;
                temp = graph[j].size();
                if(temp > threat)
                    threat = temp;
            }
        }
        if(!flag)
            answers[i] = 0;
        else
            answers[i] = temp + 1;
    }
    for(int i = 0; i < t; i++)
        cout<<answers[i]<<"\n";
}
