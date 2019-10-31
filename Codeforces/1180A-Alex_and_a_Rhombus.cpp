#include <bits/stdc++.h>

using namespace std;


int calc(int n)
{
    if(n == 1)
        return 1;
    else
        return(calc(n-1) + (int)pow(2, n));
}
int main()
{
    int n;
    cin>>n;

    if(n == 1)
        cout<<1;
    else
    {
        int sum = 0;
        int temp = n + (n - 1);
        sum = temp;
        while(temp >= 3)
        {
            temp -= 2;
            sum += (2*temp);
        }
        cout<<sum;
    }
}
