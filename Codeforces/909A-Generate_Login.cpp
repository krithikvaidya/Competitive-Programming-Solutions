#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2, str;
    cin>>s1>>s2;
    
    str.push_back(s1[0]);
    int i = 1;
    
    while(i < s1.size() && s1[i] < s2[0])
    {
        str.push_back(s1[i]);
        i++;
    }
    str.push_back(s2[0]);
    cout<<str;
}
