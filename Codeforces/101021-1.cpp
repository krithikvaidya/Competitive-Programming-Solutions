#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int lb = 0, ub = 1000001, curr;
    string ans;

    for (int i = 0; i < 25; i++)
    {
        curr = (ub + lb) / 2;
        cout << curr << endl;

        cin >> ans;
        if (ans == "<")
        {   

            ub = curr;

            if (ub == lb + 1)
            {
                curr = lb;
                break;
            }
        }
        else
        {

            lb = curr;

            if (ub == lb + 1)
            {
                curr = lb;
                break;
            }
        }
    }

    cout << "! " << curr << "\n";

}
