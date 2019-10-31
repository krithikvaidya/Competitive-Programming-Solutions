#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n, flag = 0;
        cin >> n;
        int arr[n];
        flag = 1;
        for(int j = 0; j < n; j++)
        {
            cin >> arr[j];
            if(arr[j] != -1)
                flag = 0;
        }
        string s;
        cin.ignore();
        getline(cin, s);
        if(flag)
        {
            cout << "YES\n";
            continue;
        }
        int j;
        for(j = 0; j < n; j++)
        {
            if(arr[j] != -1)
                break;
        }
        int temp = j;
        j--;
        int start = 0, end = 0;
        if(j != -1)
        {
            if(s[j] == '=')
            {
                start = arr[j+1];
                end = arr[j+1];
            }
            else if(s[j] == '<')
            {
                start = 0;
                end = arr[j+1] - 1;
                if(end < 0)
                {
                    cout << "NO\n";
                    continue;
                }
            }
            else
            {
                start = arr[j+1] + 1;
                end = INT_MAX;
                if(start > INT_MAX)
                {
                    cout << "NO\n";
                    continue;
                }
            }
            j--;
            flag = 0;
            while(j >= 0)
            {
                if(s[j] == '=')
                {
                    // DO nothing
                }
                else if(s[j] == '<')
                {
                    if(end == 0)
                    {
                        //cout << "NO\n";
                        flag = 1;
                        break;
                    }
                    else
                    {
                        start = 0;
                        end--;
                    }
                }
                else
                {
                    start++;
                    end = INT_MAX;
                    if(start > INT_MAX)
                    {
                        flag = 1;
                        break;
                    }
                }
                j--;
            }
        }
        else
        {
            start = 0;
            end = INT_MAX;
        }
        if(flag)
        {
            cout << "NO\n";
            continue;
        }
        for(int j = temp; j < n - 1; j++)
        {
            if(arr[j+1] != -1)
                continue;
            if(s[j] == '=')
            {
                start = arr[j];
                end = arr[j];
            }
            else if(s[j] == '<')
            {
                start = arr[j] + 1;
                end = INT_MAX;
                if(start > INT_MAX)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                start = 0;
                end = arr[j] - 1;
                if(arr[j] - 1 < 0)
                {
                    flag = 1;
                    break;
                }
            }
            j++;
            while(j < n - 1 && arr[j] == -1)
            {
                //cout << "\nWe are currently at index "<<j<<" and our range is "<<start<<", "<<end << "\n";
                if(s[j] == '=')
                {
                    // DO nothing
                }
                else if(s[j] == '<')
                {
                    start++;
                    end = INT_MAX;
                    if(start > INT_MAX)
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    start = 0;
                    end--;
                    if(end < 0)
                    {
                        //cout << "NO\n";
                        flag = 1;
                        break;
                    }
                }
                j++;
            }
            if(flag)
            {
                break;
            }
            if(j == n - 1)
            {
                if(arr[j] != -1)
                {
                    if(!((start <= arr[j]) && (arr[j] <= end)))
                    {
                        //cout << "NO\n";
                        flag = 1;
                        break;
                    }
                }
                break;
            }
            if(!((start <= arr[j]) && (arr[j] <= end)))
            {
                //cout << "NO\n";
                flag = 1;
                break;
            }
            j--;
            // cout << "hemmm3\n";
        }
        if(!flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
