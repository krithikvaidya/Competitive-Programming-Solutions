#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;

    int outputs[t] = { 0 };

    for(int j = 0; j < t; j++)
    {
        int n;
        cin>>n;

        int a[n];

        for(int i = 0; i < n; i++)
            cin>>a[i];

        for(int i = 0; i < n; i++)
        {
            if(a[i] == -1)
                continue;

            if(a[i] % 3 == 0)
            {
                outputs[j]++;
            }

            else
            {
                if(a[i] % 3 == 1)
                {
                    for(int k = i + 1; k < n; k++)
                        if(a[k] % 3 == 2)
                        {

                            a[i] = -1;
                            a[k] = -1;
                            outputs[j]++;
                            break;
                        }
                }
                else if(a[i] % 3 == 2)
                {
                    for(int k = i + 1; k < n; k++)
                        if(a[k] % 3 == 1)
                        {

                            a[k] = -1;
                            a[i] = -1;
                            outputs[j]++;
                            break;
                        }
                }
            }
        }



        for(int i = 0; i < n; i++)
        {
            if(a[i] % 3 == 1)
            {
                for(int k = i + 1; k < n; k++)
                {
                    if(a[k] % 3 == 1)
                    {
                        for(int l = k + 1; l < n; l++)
                        {
                            if(a[l] % 3 == 1)
                            {

                                a[i] = -1;
                                a[k] = -1;
                                a[l] = -1;
                                outputs[j]++;
                                goto outer1;
                            }
                        }
                    }
                }
            }
            outer1:
                continue;
        }

        for(int i = 0; i < n; i++)
        {
            if(a[i] % 3 == 2)
            {
                for(int k = i + 1; k < n; k++)
                {
                    if(a[k] % 3 == 2)
                    {
                        for(int l = k + 1; l < n; l++)
                        {
                            if(a[l] % 3 == 2)
                            {
                                a[i] = -1;
                                a[k] = -1;
                                a[l] = -1;
                                outputs[j]++;
                                goto outer2;
                            }
                        }
                    }
                }
            }
            outer2:
                continue;
        }
    }

    for(int i = 0; i < t; i++)
        cout<<outputs[i]<<endl;
}
