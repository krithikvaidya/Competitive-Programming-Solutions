#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r, x;
    cin>>n>>l>>r>>x;

    int c[n];

    for(int i = 0; i < n; i++)
        cin>>c[i];

    int max = (int)pow(2, n) - 1;

    int temp, ctr, mindiff, maxdiff;
    int valid = 0;
    int steps;
    int total;
    while(max > 0)
    {
        temp = max;
        ctr = 0;
        mindiff = INT_MAX;
        maxdiff = INT_MIN;
        steps = 0;
        total = 0;
        while(temp > 0)
        {
            if(temp & 1)
            {
                if(c[ctr] > maxdiff)
                    maxdiff = c[ctr];
                if(c[ctr] < mindiff)
                    mindiff = c[ctr];
                steps++;
                total += c[ctr];

            }
            temp = temp>>1;
            ctr++;
        }

        if(maxdiff - mindiff >= x && steps >= 2 && (total >= l && total <= r))
            valid++;
        max--;
    }

    cout<<valid;
}
