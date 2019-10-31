#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<int> st;
    int flag = 1;
    for(char c: s)
    {
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
        else if(c == '}')
        {
            if(st.size() != 0 && st.top() == '{')
                st.pop();
            else
            {
                flag = 0;
                break;
            }
        }
        else if(c == ')')
        {
            if(st.size() != 0 && st.top() == '(')
                st.pop();
            else
            {
                flag = 0;
                break;
            }
        }
        else if(c == ']')
        {
            if(st.size() != 0 && st.top() == '[')
                st.pop();
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if(flag && st.size() == 0)
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

