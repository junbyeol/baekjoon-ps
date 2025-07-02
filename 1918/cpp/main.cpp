#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char now = str[i];
        if ('A' <= now && now <= 'Z')
            cout << now;
        else
        {
            if (now == '+' || now == '-')
            {
                while (!st.empty() && st.top() != '(')
                {
                    cout << st.top();
                    st.pop();
                }
                st.push(now);
            }
            else if (now == '*' || now == '/')
            {
                while (!st.empty() && (st.top() == '*' || st.top() == '/'))
                {
                    cout << st.top();
                    st.pop();
                }
                st.push(now);
            }
            else if (now == '(')
            {
                st.push(now);
            }
            else // ')'
            {
                while (!st.empty() && st.top() != '(')
                {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << "\n";

    return 0;
}
