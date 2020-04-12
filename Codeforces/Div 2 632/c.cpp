#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];

    long long int tot_sum = 0ll;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot_sum += a[i];
    }

    long long int sum_of_left[n], sum_of_right[n];
    long long int prev_sum = 0, post_sum = 0;

    sum_of_left[0] = 0;
    sum_of_right[n - 1] = 0;

    for (int i = 1; i < n; i++)
    {
        post_sum += a[i - 1];
        sum_of_left[i] = post_sum;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        prev_sum += a[i + 1];
        sum_of_right[i] = prev_sum;
    }

    map <long long int, pair<long long int, int> > neg_sum_to_find;

    long long int possb_subarrays = 0ll;
    int curr_max_removal = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            curr_max_removal = i + 1;
            possb_subarrays += (n - i);
            possb_subarrays -= (curr_max_removal);
            continue;
        }
        possb_subarrays += (n - i);

        auto it = neg_sum_to_find.find(tot_sum - sum_of_right[i]);

        // Check if element exists in map or not
        if (it != neg_sum_to_find.end())
            curr_max_removal = max (curr_max_removal, (neg_sum_to_find[tot_sum - sum_of_right[i]].second + 1));

        possb_subarrays -= curr_max_removal;
        neg_sum_to_find[sum_of_left[i]] = make_pair(sum_of_left[i], i);

    }

    cout << possb_subarrays;
}

