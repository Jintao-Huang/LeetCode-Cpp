
#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline void reverseString(vector<char>& s) { reverse(s.begin(), s.end()); }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    cout << s << '\n';
}