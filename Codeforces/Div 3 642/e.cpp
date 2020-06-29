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

        cin.ignore();

        string s;
        cin >> s;

        int flip_capacity = 0;
        int r = s.size();

        for (int j = 0; j < r; j++)
        {
            char ch = s[j];
            if (ch == '1')
            {
                int l;
                for (l = 1; l <= flip_capacity + 1; l++)
                {
                    if (j + l * k < r)
                    {
                        if (s[j + l * k] == '1')
                        {
                            flip_capacity += l - 1;

                            for (int y = j + l; y < j + l * k; y++)
                                s[j] = '1';
                                
                            for (int m = j + 1; m < j + l * k; m++)
                                if (s[m] == '1')
                                    flip_capacity++;
                            j = j + l * k;

                            break;   

                        }
                        
                    }
                    else
                    {
                        for (int m = j + 1; m < r; m++)
                            if (s[m] == '1')
                                flip_capacity++;
                        goto hmm;
                    }
                    
                }

                if (l == flip_capacity + 2)
                {
                    flip_capacity++;
                    actual_flips++;
                }
                    

                // flip_capacity++;
            }
        }

        hmm:
            cout << flip_capacity << "\n";
    }

}
