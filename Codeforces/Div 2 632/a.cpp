#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int row, col;
        cin >> row >> col;

        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                if (j != row - 1 || k != col - 1)
                    cout << "B";
                else
                    cout << "W";
            }
            cout << "\n";
        }
    }
}
