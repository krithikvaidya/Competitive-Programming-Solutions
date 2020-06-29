#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

void bisect (vector<int> &a, priority_queue <tuple<int, int, int>> &segments, int step)
{
    if (segments.empty())
    {
        return;
    }

    int lb = get<2>(segments.top());
    int ub = -1 * get<1>(segments.top());

    segments.pop();

    int index = (lb + ub) / 2;
    a[index] = step;

    step++;

    if (index - 1 >= lb)
        segments.push (make_tuple(index - lb, -1 * (index - 1), lb));
    if (index + 1 <= ub)
        segments.push (make_tuple(ub - index, -1 * ub, index + 1));

    bisect (a, segments, step);
}

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

        priority_queue <tuple<int, int, int>> segments; 
        
        segments.push (make_tuple(n, 1 - n, 0));

        bisect (a, segments, 1);

        for (int c: a)
            cout << c << " ";

        cout << "\n";

    }

}
