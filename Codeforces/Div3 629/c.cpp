#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    int n, k;
    string x;
    string a, b;
    int val;

    for (int i = 0; i < t; i++)
    {
        a = "";
        b = "";

        cin >> n;
        cin.ignore();
        
        int curr_turn = 0, curr_turn_o = 0;
        cin >> x;

        for (char ch: x)
        {
            val = int(ch - '0');
            if (val == 2)
            {
                if (curr_turn == 0)
                {
                    a.push_back('1');
                    b.push_back('1');
                }
                else {
                a.push_back('0');
                b.push_back('2');}
            }

            else if (val == 1)
            {
                if (curr_turn == 0)
                {
                    a.push_back('1');
                    b.push_back('0');
                    curr_turn++;
                }
                else
                {
                    b.push_back('1');
                    a.push_back('0');
                }
                
            }

            else
            {
                a.push_back('0');
                b.push_back('0');
            }
            
        }

        cout << a << "\n" << b << "\n";

    }
}