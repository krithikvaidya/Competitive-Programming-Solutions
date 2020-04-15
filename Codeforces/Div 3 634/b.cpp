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
        int n, a, b;
        cin >> n >> a >> b;

        string str = "";

        for (int i = 0; i < b; i++)
            str.push_back(char(97 + i));
        
        string new_str = "";

        while (new_str.size() < n)
        {
            new_str += str;
        }

        while (new_str.size() > n)
            new_str.pop_back();

        cout << new_str << "\n";
    }

}
