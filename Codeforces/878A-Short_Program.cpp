#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    int a = 1023;
    int b = 0;
    char op;
    int temp;

    for(int i = 0; i < n; i++)
    {
        cin>>op>>temp;
        cin.ignore();

        if(op == '|')
        {
            a = a|temp;
            b = b|temp;
        }
        else if(op == '&')
        {
            a = a&temp;
            b = b&temp;
        }
        else
        {
            a = a^temp;
            b = b^temp;
        }
    }

    int a1, b1;
    bitset<10> OR;
    bitset<10> XOR;

    for(int i = 0; i < 10; i++)
    {
        a1 = a&1;
        b1 = b&1;
        a = a>>1;
        b = b>>1;

        if(a1 == 1 && b1 == 0)
        {
            OR[i] = 0;
            XOR[i] = 0;
        }
        else if(a1 == 0 && b1 == 1)
        {
            OR[i] = 0;
            XOR[i] = 1;
        }
        else if(a1 == 1 && b1 == 1)
        {
            OR[i] = 1;
            XOR[i] = 0;
        }
        else
        {
            OR[i] = 1;
            XOR[i] = 1;
        }
    }
    cout<<2<<endl;
    cout<<"| "<<OR.to_ullong()<<endl;
    cout<<"^ "<<XOR.to_ullong()<<endl;


}
