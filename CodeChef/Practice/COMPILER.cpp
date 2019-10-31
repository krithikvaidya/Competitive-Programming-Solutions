#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    for(int i = 0; i < t; i++)
    {
        string str;
        getline(cin, str);
        stack<char> st;
        int len = 0;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == '<')
                st.push(str[j]);
            else
            {
                if(st.empty())
                    break;
                else
                {
                    st.pop();
                    if(st.empty())
                    {
                        len = j+1;
                    }
                }
            }
        }
        cout<<len<<endl;
    }
}
