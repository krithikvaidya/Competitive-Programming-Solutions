#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int last_index[26], distance[26], first_index[26];

    fill(first_index, first_index + 26, -1);
    fill(last_index, last_index + 26, -1);
    fill(distance, distance + 26, INT_MIN);

    char ch;
    for(int i = 0; i < s.length(); i++)
    {
        ch = s[i];
        if(first_index[(ch - 97)] == -1)
        {

            first_index[ch - 97] = i;
            last_index[ch - 97] = i;
        }
        else
        {
            if(i - last_index[ch - 97] > distance[ch - 97])
                distance[ch - 97] = i - last_index[ch - 97];
            last_index[ch - 97] = i;
        }
    }

    int min_k = INT_MAX, temp;

    for(int i = 0; i < 26; i++)
    {
        if(first_index[i] != -1)
        {
            // cout<<"HMM";
            temp = (first_index[i] + 1) > (s.length() - last_index[i]) ? (first_index[i] + 1) : (s.length() - last_index[i]);

            if(distance[i] != INT_MAX)
                temp = temp > (distance[i]) ? temp : (distance[i]);

            if(temp < min_k)
                min_k = temp;
        }
    }

    cout << min_k;
}
