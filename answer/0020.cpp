#include "pre.h"

class Solution
{
public:
    bool isValid(const string &s)
    {
        stack<char> st;
        for (const char &c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;
            //
            case ')':
                if (st.empty() || st.top() != '(')
                {
                    return false;
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                {
                    return false;
                }
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                {
                    return false;
                }
                st.pop();
                break;
            }
        }
        return st.empty();
    }
};

class Solution2
/// 使用hashmap
{
public:
    bool isValid(const string &s)
    {
        unordered_map<char, char> mapper = {
            {')', '('},
            {']', '['},
            {'}', '{'}};
        stack<char> st;
        for (const char &c : s)
        {
            if (mapper.count(c))
            {
                if (st.empty() || st.top() != mapper[c])
                {
                    return false;
                }
                st.pop();
                continue;
            }
            //
            st.push(c);
        }
        return st.empty();
    }
};

int main()
{
    string s = "()";
    cout << Solution().isValid(s) << '\n';
    cout << Solution2().isValid(s) << '\n';
}