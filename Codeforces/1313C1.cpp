#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;
long long int final_max;

void calc_ht (int floors[], int index, int n, int prev_ht, int peak_occured, long long int cur_ht)
{
    if (index == n)
    {
        final_max = max (final_max, cur_ht);
        return;
    }

    if ((floors[index] <= prev_ht) || (floors[index] > prev_ht && peak_occured))
    {
        cur_ht = cur_ht + prev_ht;
        calc_ht (floors, index + 1, n, floors[index], peak_occured, cur_ht);
    }
    else
    {
        if (index < n - 1 && floors[index] > floors[index + 1])
            // peak here
        else if (index < n - 1 && floors[index] < floors[index + 1])
        {
            // peak definitely not here
        }
        else if (index < n - 1 && floors[index] == floors[index + 1])
        {
            // find the next increase/decrease, and decide accordingly.
            // if index reaches n, decide accordingly
        }
        
    }
    
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int floors[n];

    for (int i = 0; i < n; i++)
        cin >> floors[i];




}
