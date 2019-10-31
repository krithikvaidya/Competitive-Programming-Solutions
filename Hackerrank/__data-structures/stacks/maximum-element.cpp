#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int data;
    Stack* next;
};

Stack* push(int val)
{
    Stack* node = new Stack();
    node -> data = val;
    node -> next = NULL;
    return node;
}

int printMax(Stack* top)
{
    int max = INT_MIN;
    while(top != NULL)
    {
        if(top -> data > max)
            max = top -> data;
        top = top -> next;
    }
    return max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;  

    int q, val;
    cin>>q>>val;

    int max = val;
    Stack* temp;
    Stack* top = push(val);

    for(int i = 1; i < n; i++)
    {
        cin>>q;
        if(q == 1)
        {
            cin >> val;
            if(val > max)
                max = val;
            temp = push(max);
            temp -> next = top;
            top = temp;
        }
        else if(q == 2)
        {
            temp = top;
            if(top -> next == NULL)
                max = INT_MIN;
            
            else if((top -> next) -> data < top -> data)
                max = (top -> next) -> data;
            
            top = top -> next;
            delete temp;
        }
        else   
        {
            cout << top -> data << endl;
        }
    }
    return 0;
}

