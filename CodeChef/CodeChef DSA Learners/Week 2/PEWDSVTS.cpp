#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;

        int contrib;
        priority_queue <int> contribs; 

        for (int j = 0; j < n; j++)
        {
            cin >> contrib;
            contribs.push(contrib);
        }

        int pp_gain_req = z - a;
        int hooli_gain_req = z - b;

         int days_till_hooli_reach_z;

        if (hooli_gain_req % y == 0)
            days_till_hooli_reach_z = hooli_gain_req / y;
        else
        {
            days_till_hooli_reach_z = hooli_gain_req / y + 1;
        }

        int pp_gain = x * (days_till_hooli_reach_z - 1);
        int ctr = 0;
        int curr;
        while (contribs.top() != 0 && pp_gain < pp_gain_req)
        {
            cout << "\ntop: " << contribs.top() << "\n";
            curr = contribs.top();
            pp_gain += curr;
            contribs.pop();
            contribs.push((curr / 2));
            ctr++;
        }

        if (pp_gain < pp_gain_req)
            cout << "RIP\n";
        else
        {
            cout << ctr << "\n";
        }
        

    }
}