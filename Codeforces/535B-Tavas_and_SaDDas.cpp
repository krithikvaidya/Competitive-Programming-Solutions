#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int i = 0;
    int pos = 0;
    while(n > 0)
    {
        if(n%10 == 4)
            pos += (int)pow(2, i);
        else
        {
            pos += (int)pow(2, i+1);
        }


        i++;
        n/=10;
    }

    cout<<pos;
}
