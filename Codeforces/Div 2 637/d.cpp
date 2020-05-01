#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

char getVal(string str)
{
    int onecount = 0;
    for (char ch : str)
        if (ch == '1')
            onecount++;

    return onecount;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    cin.ignore();

    string number = "";
    int spcl = -1;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if (k == 0 || spcl != -1)
        {
            continue;
        }

        char num = getVal(str);

        if (str[6] == '1') // it will be an 8
        {
            if (7 - num <= k)
            {
                spcl = i;
                continue;
            }
        }

        else
        {
            if (6 - num > k)
            {
                // largest value formable? and then k -= reqd
                spcl = i;
                continue;
            }
            else
            {
                number += '9';
                k -= (6 - num);
                continue;
            }
        }
    }

    if (spcl)
    {
    }
    else
    {
        if (k != 0)
        {
            for (int k = n - 1; k >= 0; k--)
            {
                if (number[k] == '9')
                {
                    number[k] = '8';
                    k--;
                    if (k == 0)
                        break;
                }
            }
        }

        if (k != 0)
            -1 else
            {
                /* code */
            }
    }
}
