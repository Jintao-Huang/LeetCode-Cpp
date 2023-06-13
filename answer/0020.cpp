#include <leetcode>
using namespace leetcode;

/// 使用switch case
class Solution {
   public:
    bool isValid(const string &s) {
        vector<char> st;
        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    st.push_back(c);
                    break;
                //
                case ')':
                    if (st.empty() || st.back() != '(') {
                        return false;
                    }
                    st.pop_back();
                    break;
                case ']':
                    if (st.empty() || st.back() != '[') {
                        return false;
                    }
                    st.pop_back();
                    break;
                case '}':
                    if (st.empty() || st.back() != '{') {
                        return false;
                    }
                    st.pop_back();
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
        vector<char> st;
        for (char c : s) {
            if (mapper.count(c)) {
                if (st.empty() || st.back() != mapper[c]) {
                    return false;
                }
                st.pop_back();
                continue;
            }
            //
            st.push_back(c);
        }
        return st.empty();
    }
};

/// 使用if else
class Solution3 {
   public:
    inline bool isValid(const string &s) { return bracket_matching(s); }
};

int main() {
    string s = "()";
    cout << Solution().isValid(s) << '\n';
    cout << Solution2().isValid(s) << '\n';
    cout << Solution3().isValid(s) << '\n';
    return 0;
}