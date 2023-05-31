#include <leetcode>
using namespace leetcode;
class Solution {
   public:
    bool isValid(const string &s) {
        stack<char> st;
        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    st.push(c);
                    break;
                //
                case ')':
                    if (st.empty() || st.top() != '(') {
                        return false;
                    }
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') {
                        return false;
                    }
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{') {
                        return false;
                    }
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};

/// 使用hashmap

class Solution2 {
   public:
    bool isValid(const string &s) {
        unordered_map<char, char> mapper = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        for (char c : s) {
            if (mapper.count(c)) {
                if (st.empty() || st.top() != mapper[c]) {
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

/// 使用if else
class Solution3 {
   public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == ')' || c == ']' || c == '}') {
                if (st.empty() || c == ')' && st.top() != '(' || c == ']' && st.top() != '[' ||
                    c == '}' && st.top() != '{') {
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

int main() {
    string s = "()";
    cout << Solution().isValid(s) << '\n';
    cout << Solution2().isValid(s) << '\n';
    cout << Solution3().isValid(s) << '\n';
    return 0;
}