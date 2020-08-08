/* C++ program to implement basic stack 
   operations */

#include <bits/stdc++.h> 
  
using namespace std; 
  
class Stack { 

    int top_index; 
  
public: 
    vector<int> st; 
  
    Stack() 
    { 
        top_index = -1; 
    } 

    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 

}; 
  
bool Stack::push(int x) 
{
    st.emplace_back(x); 
    ++top_index;

    cout << x << " pushed into stack\n"; 
    return true; 
} 
  
int Stack::pop() 
{ 
    if (top_index < 0) { 
        cout << "Stack Underflow"; 
        return numeric_limits<int>::min(); 
    } 

    else {
        int x = st[top_index--]; 
        st.pop_back();
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top_index < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
    
        return st[top_index]; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top_index < 0); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n";
    cout << s.pop() << " Popped from stack\n";
    cout << s.pop() << " Popped from stack\n";
    cout << s.pop() << " Popped from stack\n"; 
  
    return 0; 
} 