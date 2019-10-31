#include <bits/stdc++.h>

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define fast ios::sync_with_stdio(0); cin.tie(0);

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int q;
    cin>>q;

    int ylower, xlower, yupper, xupper;

    int n; int flag;
    int x, y, f1, f2, f3, f4;

    string outputs[q];

    for(int i = 0; i < q; i++)
    {
        flag = 1;
        cin>>n;
        ylower = -100000;
        xlower = -100000;
        yupper = 100000;
        xupper = 100000;

        for(int j = 0; j < n; j++)
        {
            cin>>x>>y;
            cin>>f1>>f2>>f3>>f4;

            if(flag == 0)
                continue;

            if(f1 == 0)
            {
                if((xupper < x))
                {
                    //cout<<1<<"\n";
                    outputs[i] = "0";
                    flag = 0;
                }
                if(x > xlower)
                    xlower = x;
            }
            if(f2 == 0)
            {
                if((ylower > y))
                {
                    //cout<<2<<"\n";
                    outputs[i] = "0";
                    flag = 0;
                }
                if(y < yupper)
                    yupper = y;
            }
            if(f3 == 0)
            {
                if((xlower > x))
                {
                    //cout<<3<<"\n";
                    outputs[i] = "0";
                    flag = 0;
                }
                if(x < xupper)
                    xupper = x;
            }
            if(f4 == 0)
            {
                if((yupper < y))
                {
                    //cout<<4<<"\n";
                    outputs[i] = "0";
                    flag = 0;
                }
                if(y > ylower)
                    ylower = y;
            }
            // cout << "\n" << xlower << "\n" << xupper << "\n" << ylower << "\n" << yupper << "\n";
        }

        if(flag)
        {
            if((xupper < xlower) || (yupper < ylower))
                outputs[i] = "0";
            else if(xlower > 100000)
                outputs[i] = "0";
            else if(xupper < -100000)
                outputs[i] = "0";
            else if(ylower > 100000)
                outputs[i] = "0";
            else if(yupper < -100000)
                outputs[i] = "0";
            else
            {
                if(xlower < -100000)
                    x = -100000;
                else if(xupper > 100000)
                    x = 100000;
                else
                    x = xupper;

                if(ylower < -100000)
                    y = -100000;
                else if(yupper > 100000)
                    y = 100000;
                else
                    y = yupper;

                outputs[i] = "1 " + to_string(x) + " " + to_string(y);
            }
        }
    }

    for(int i = 0; i < q; i++)
        cout << outputs[i] << "\n";
}
