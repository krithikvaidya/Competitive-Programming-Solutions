#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector<int> a;

int check()
{

}

int main()
{
    int n;
    cin>>n;

    int temp;

    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    vector<int> e;
    vector<int> f;

    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        if(temp == 4)
            a.push_back(i);
        else if(temp == 8)
            b.push_back(i);
        else if(temp == 15)
            c.push_back(i);
        else if(temp == 16)
            d.push_back(i);
        else if(temp == 23)
            e.push_back(i);
        else if(temp == 42)
            f.push_back(i);
    }

    int ai = 0;
    int bi = 0;
    int ci = 0;
    int di = 0;
    int ei = 0;
    int fi = 0;

    int delete_count = 0;
    for(int i = 0; (ai < a.size()) && (bi < b.size()) && (ci < c.size()) && (di < d.size()) && (ei < e.size()) && (fi < f.size()); i++)
    {
        if(b[bi] < a[ai])
        {
            delete_count++;
            bi++;
            continue;
        }
        else if(c[ci] < b[bi])
        {
            delete_count++;
            ci++;
            continue;
        }

        else if(d[di] < c[ci])
        {
            delete_count++;
            di++;
            continue;
        }
        else if(e[ei] < d[di])
        {
            delete_count++;
            ei++;
            continue;
        }
        else if(f[fi] < e[ei])
        {
            delete_count++;
            fi++;
            continue;
        }

        ai++;
        bi++;
        ci++;
        di++;
        ei++;
        fi++;
    }

    delete_count += - ai + a.size() - bi + b.size() - ci + c.size() - di + d.size() - ei + e.size() - fi+f.size();

    cout<<delete_count;
}
