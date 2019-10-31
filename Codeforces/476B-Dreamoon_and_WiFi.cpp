#include <bits/stdc++.h>

using namespace std;

long double fact(int n)
{
    long double res = 1.0;
    for(int i = 2; i <= n; i++)
        res *= i;
    return res;
}
int main()
{
    string str1, str2;
    cin>>str1>>str2;

    int sum = 0;

    for(char ch: str1)
    {
        sum = sum + (ch == '+'?1:-1);
    }
    int sum2 = 0, q_ct = 0;
    for(char ch: str2)
    {
        if(ch == '+')
            sum2++;
        else if(ch == '-')
            sum2--;
        else
            q_ct++;
    }

    cout<<setprecision(10);
    if(abs(sum - sum2) > q_ct)
        cout<<0;
    else
    {
        int val = sum2 - sum;
        long double prob = 1;

        if(q_ct == 0)
            cout<<1;
        else
        {
            val = abs(val);

            if((q_ct - val) % 2 != 0)
                cout<<0;
            else
            {
                int ones = val + (q_ct - val)/2;
                int zeroes = q_ct - ones;

                prob = ((long double)fact(q_ct))/(fact(ones) * fact(zeroes));
                prob /= (long double)pow(2, q_ct);
                cout<<prob;
            }
        }
    }
}
