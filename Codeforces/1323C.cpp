#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;   
    cin.ignore();

    string seq;
    cin >> seq;

    stack <char> st;
    int cost = 0;

    for (int i = 0; i < seq.size(); i++)
    {
        if (seq[i] == '(')
            st.push('(');
        else
        {
            if (st.empty())
            {
                int close = 1, open = 0;
                i++;
                while (i < seq.size() && close != open)
                {
                    if (seq[i] == ')')
                        close++;
                    else
                    {
                        open++;
                    }
                    i++;
                }

                // cout << "\nclose: " << close << "\nopen: " << open << "\n";

                if (close != open)
                {
                    cout << -1;
                    return 0;
                }
                
                cost += close + open;
                i--;
            }
            else
            {
                st.pop();
            }
            
        }

    }

    if (st.empty())
        cout << cost;
    else
    {
        cout << -1;
    }
    
}
