#include <bits/stdc++.h>
    using namespace std;
    int value(char x)
    {
        int y = (int)x;
        if(y >= 48 && y <= 57)
            return (y - 48);
        else
            return (y - 55);
    }
    long long int convertToDec(string str, int b)
    {
        long long int val = 0ll;
        int n = str.size();
        long long int j = 0ll, temp;
        for(int i = n - 1; i >= 0; i--)
        {
            temp = 1ll;
            if(str[i] == ' ')
                continue;
            for(int k = 1; k <= j; k++)
                temp *= (long long int)b;
            if(temp > 1000000000000ll)
                return -1ll;
            val += (value(str[i])) * temp;
            if(val > 1000000000000ll)
                return -1ll;
            j++;
        }
        return val;
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t;
        long long int x = -1ll;
        long long int temp_x, x_val;
        cin >> t;
        int n, b, flag;
        string str;
        for(int i = 0; i < t; i++)
        {
            x = -1;
            x_val = x;
            flag = 0;
            cin >> n;
            cin.ignore();
            vector<string> unknownBaseValues;
            for(int j = 0; j < n; j++)
            {
                cin >> b;
                getline(cin, str);
                if(flag)
                    continue;
                if(b == -1)
                    unknownBaseValues.push_back(str);
                else
                {
                    if(x == -1)
                    {
                        x = convertToDec(str, b);
                        if(x == -1)
                            flag = 1;
                        continue;
                    }
                    if(convertToDec(str, b) != x)
                        flag = 1;
                }
            }
            if(flag)
            {
                cout << -1 << "\n";
                continue;
            }
            if(unknownBaseValues.size() == 0)
            {
                cout << convertToDec(str, b) << "\n";
                continue;
            }
            x_val = x;
            int j;
            vector<long long int> plausible_values;
            vector<long long int> current_plausible_values;
            string val = unknownBaseValues[0];
            
            int lowestBase = 2;
            for(char ch: val)
            {
                if(ch == ' ')
                    continue;
                if(value(ch) + 1 > lowestBase)
                    lowestBase = value(ch) + 1;
            }
            for(j = lowestBase; j <= 36; j++)
            {
                temp_x = convertToDec(val, j);
                if(temp_x != -1)
                    plausible_values.push_back(temp_x);
                else
                    break;
            }
            x = x_val;
            if(x != -1)
            {
                flag = 0;
                for(long long int a: plausible_values)
                {
                    if(a == x)
                    {
                        flag = 1;
                        plausible_values.clear();
                        plausible_values.push_back(x);
                        break;
                    }
                }
                if(!flag)
                {
                    cout << -1 << "\n";
                    continue;
                }
            }
            int flag2 = 0;
            for(int j = 1; j < unknownBaseValues.size(); j++)
            {
                val = unknownBaseValues[j];
                current_plausible_values.clear();
                lowestBase = 2;
                for(char ch: val)
                {
                    if(ch == ' ')
                        continue;
                    if(value(ch) + 1 > lowestBase)
                        lowestBase = value(ch) + 1;
                }
                for(int k = lowestBase; k <= 36; k++)
                {
                    temp_x = convertToDec(val, k);
                    if(temp_x == -1)
                        break;
                    for(long long int a: plausible_values)
                        if(a == temp_x)
                        {
                            current_plausible_values.push_back(a);
                            break;
                        }
                }
                if(current_plausible_values.empty())
                {
                    cout << -1 << "\n";
                    flag2 = 1;
                    break;
                }
                plausible_values = current_plausible_values;
            }
            if(!flag2)
            {
                sort(plausible_values.begin(), plausible_values.end());
                cout << plausible_values[0] << "\n";
            }
        }
    }
