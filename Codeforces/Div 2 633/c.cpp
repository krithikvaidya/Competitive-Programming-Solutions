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
            int n;
            cin >> n;

            vector<int> a(n);

            for (int j = 0; j < n; j++)
                cin >> a[j];

            int max_enc = numeric_limits<int>::min();
            int seconds = 0;

            for (int val: a)
            {
                if (val >= max_enc)
                {
                    max_enc = val;
                    continue;
                }
                
                int diff = max_enc - val;

                int pow2 = log2(diff);

                seconds = max (seconds, pow2 + 1);
            }

            cout << seconds << "\n";
        }

    }
