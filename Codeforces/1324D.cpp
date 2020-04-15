#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int bsearch (vector<int> &arr, int val)
{
    int lb = 0;
    int ub = arr.size();
    int mid;

    while (lb <= ub)
    {
        mid = (lb + ub)/2;

        if (arr[mid] < val)
        {
            lb = mid + 1;
        }
        else if (arr[mid] > val)
        {
            ub = mid - 1;
        }
        else
        {
            break;
        }
        
    }

    return mid;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];
    int b[n];
    vector<int> diffs(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        diffs[i] = a[i] - b[i];
    }

    sort (diffs.begin(), diffs.end());
    long long int goodcount = 0;

    for (int i = 0; i < n; i++)
    {
        if (diffs[i] <= 0)
            continue;

        int pos = lower_bound(diffs.begin(), diffs.end(), -diffs[i] + 1) - diffs.begin();

        goodcount += i - pos;
    }

    cout << goodcount << "\n";

}
