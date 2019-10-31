#include <bits/stdc++.h>
using namespace std;
int main()
{
    int match[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        int res = a + b;
        int dig;
        int sum = 0;
        while (res > 0)
        {
            dig = res % 10;
            sum += match[dig];
            res /= 10;
        }
        cout << sum << "\n";
    }
}
