#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lli n, x;
    cin >> n >> x;

    vector<lli> d(2 * n);
    bool flag = false;
    lli maxx = 0ll;

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        if (d[i] >= x)
        {
            maxx = d[i];
            flag = true;
        }
    }

    if (flag)
    {
        cout << (((maxx * (maxx + 1)) / 2) - (((maxx - x) * (maxx - x + 1)) / 2)) << "\n";
        return 0;
    }

    for (int i = n; i < 2 * n; i++)
        d[i] = d[i - n];

    lli middle_sum = 0ll;
    lli leftest_month_length;
    lli curr_month_length;
    lli curr_sum = 0ll;

    lli curr_month_lengths_sum = 0ll;

    int i;
    for (i = 0; i < 2 * n; i++)
    {
        curr_month_lengths_sum += d[i];
        curr_sum += (d[i] * (d[i] + 1)) / 2;
        if (curr_month_lengths_sum <= x)
            continue;
    }

    if (i == 2 * n + 1)
    {
        curr_month_lengths_sum = 0ll;
        for (i = 0; i < 2 * n; i++)
        {
            curr_month_lengths_sum += (d[i] * (d[i] + 1)) / 2;
        }

        cout << curr_month_lengths_sum << "\n";
        return 0;
    }

    lli prev_sum, prev_days_total, leftover_days, maximum, curr_lower_index;
    maximum = -1ll;
    curr_lower_index = 0ll;
    prev_sum = curr_sum - (d[i] * (d[i] + 1)) / 2;
    prev_days_total = curr_month_lengths_sum - d[i];
    cout << prev_sum << "\n";
    for (i = i; i < 2 * n; i++)
    {
        // first try partially taking this and fully taking previous.
        // then try fully taking this and partially taking previous.
        // prev_sum = curr_sum - (d[i] * (d[i] + 1)) / 2;
        // prev_days_total = curr_month_lengths_sum - d[i];

        leftover_days = x - prev_days_total;

        if (prev_sum + ((leftover_days) * (leftover_days + 1)) / 2 > maximum)
            maximum = prev_sum + ((leftover_days) * (leftover_days + 1)) / 2;
        
        // maximum = prev_sum + ((leftover_days) * (leftover_days + 1)) / 2;
        
        prev_days_total += d[i];
        prev_sum += (d[i] * (d[i] + 1)) / 2;

        while (prev_days_total > x)
        {
            prev_sum -= (d[curr_lower_index] * (d[curr_lower_index] + 1)) / 2;
            prev_days_total -= d[curr_lower_index];
            curr_lower_index++;
        }

        leftover_days = x - prev_days_total;
        lli tryy = prev_sum + (((d[curr_lower_index] * (d[curr_lower_index] + 1)) / 2) - (((d[curr_lower_index] - leftover_days) * (d[curr_lower_index] - leftover_days + 1)) / 2));
 
        if (tryy > maximum)
            maximum = tryy;
    }

    cout << maximum << "\n";
}
