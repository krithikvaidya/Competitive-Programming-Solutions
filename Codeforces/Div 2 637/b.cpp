#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int j = 0; j < n; j++)
            cin >> a[j];

        long long t = 0;

        vector<int> peaks(n);

        for (int j = 1; j < n - 1; j++)
        {
            if (a[j] > a[j - 1] && a[j + 1] < a[j])
                peaks[j] = 1;
        }

        int curr_peaks = 0;

        for (int j = 1; j < n && j < k - 1; j++)
        {
            if (peaks[j])
                curr_peaks++;
        }

        int l = 0;
        int max_peaks = curr_peaks;

        for (int j = k; j < n; j++)
        {
            if (peaks[j - k + 1])
                curr_peaks--;

            if (peaks[j - 1])
                curr_peaks++;

            if (curr_peaks > max_peaks)
            {
                max_peaks = curr_peaks;
                l = j - k + 1;
            }
        }

        cout << max_peaks + 1 << " " << l + 1 << "\n";

        // print l is 1 indexed
    }
}
