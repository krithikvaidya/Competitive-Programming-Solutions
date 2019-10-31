#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string answers[t];
    for(int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        int val[n];
        long long total = 0ll;
        for(int j = 0; j < n; j++)
        {
            cin>>val[j];
            total += val[j];
        }
        if(total % n != 0)
            answers[i] = "Impossible";
        else
        {
            long long torem = total/n;
            int j;
            for(j = 0; j < n; j++)
            {
                if(val[j] == torem)
                {
                    //cout<<val[j]<<endl;
                    answers[i] = to_string(j + 1);
                    break;
                }
            }
            if(j == n)
                answers[i] = "Impossible";
        }
    }
    for(int i = 0; i < t; i++)
        cout<<answers[i]<<endl;
}
