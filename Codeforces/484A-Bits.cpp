#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    long long answers[n];

    for(int i = 0; i < n; i++)
    {
        long long l, r;
        cin>>l>>r;

        long long r1 = r, r2 = r;
        int max_pwr = 0;
        int flag = 0;

        while(r2 != 0)
        {
            max_pwr++;
            if(!(r2&1))
                flag = 1;
            r2 = r2>>1;
        }

        if(!flag)
        {
           answers[i] = r;
        }
        else
        {
            if(l==r)
            {
                answers[i] = r;
                continue;
            }
            long long r3 = r;
            string bits = "";
            while(r3 > 0)
            {
                bits.push_back(char((r3&1) + 48));
                r3 = r3>>1;
            }
            long long hmm = __builtin_popcount(r);
            long long val = LLONG_MAX;
            for(int j = bits.size() - 1; j >= 0; j--)
            {
                if(bits[j] == '1')
                {
                    string bits2(bits);
                    bits2[j] = '0';
                    for(int k = j-1; k >= 0; k--)
                        bits2[k] = '1';
                    reverse(bits2.begin(), bits2.end());
                    val = stoull(bits2, 0, 2);

                    if(val >= l)
                    {
                        answers[i] = val;
                        break;
                    }
                }
            }

            if(hmm >__builtin_popcount(val) && val != LLONG_MAX)
                answers[i] = r;
            if(val == LLONG_MAX)
                answers[i] = 0;
        }
    }

    for(int i = 0; i < n; i++)
        cout<<answers[i]<<"\n";
}
