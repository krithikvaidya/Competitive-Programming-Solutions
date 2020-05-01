#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

long long int fence_count;

void count_fences (map <pair<int, int>, int> &plants, pair<int, int> coords, int n, int m)
{
    
    int row = coords.first;
    int col = coords.second;

    if (plants[make_pair(row, col)] == 2)
        return;

    plants[make_pair(row, col)] = 2;

    if (row + 1 >= n)
    {
        fence_count++;
    }
    else if (plants[make_pair(row + 1, col)] != 0 && plants[make_pair(row + 1, col)] != 2)
    {
        count_fences(plants, make_pair(row + 1, col), n, m);
    }
    else if (plants[make_pair(row + 1, col)] != 2)
    {
        fence_count++;
    }
    

    if (row - 1 < 0)
    {
        fence_count++;
    }
    else if (plants[make_pair(row - 1, col)] != 0 && plants[make_pair(row - 1, col)] != 2)
    {
        count_fences(plants, make_pair(row - 1, col), n, m);
    }
    else if (plants[make_pair(row - 1, col)] != 2)
    {
        fence_count++;
    }

    if (col + 1 >= m)
    {
        fence_count++;
    }
    else if (plants[make_pair(row, col + 1)] != 0 && plants[make_pair(row, col + 1)] != 2)
    {
        count_fences(plants, make_pair(row, col + 1), n, m);
    }
    else if (plants[make_pair(row, col + 1)] != 2)
    {
        fence_count++;
    }

    if (col - 1 < 0)
    {
        fence_count++;
    }
    else if (plants[make_pair(row, col - 1)] != 0 && plants[make_pair(row, col - 1)] != 2)
    {
        count_fences(plants, make_pair(row, col - 1), n, m);
    }
    else if (plants[make_pair(row, col - 1)] != 2)
    {
        fence_count++;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        fence_count = 0;
        int n, m, k, r, c;
        cin >> n >> m >> k;

        map <pair<int, int>, int> plants;
        vector<pair<int, int>> coords;

        for (int j = 0; j < k; j++)
        {
            cin >> r >> c;
            plants[make_pair(r - 1, c - 1)] = 1;
            coords.push_back(make_pair(r - 1, c - 1));
        }

        for (auto coord: coords)
            count_fences(plants, coord, n, m);
        
        cout << fence_count << "\n";
    }


}
