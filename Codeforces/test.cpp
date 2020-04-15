#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    vector <int> vec = { 2, 4, 4, 10, 12};

    int val1 = 1;
    int val2 = 13;

    cout << lower_bound(vec.begin(), vec.end(), val2) - vec.begin();

}
