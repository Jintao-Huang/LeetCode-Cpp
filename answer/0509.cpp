#include <leetcode>
using namespace leetcode;

class Solution {
public:
    inline int fib(int n) {
        return ::fib(n);
    }
};

/// 通项公式法(组合数学), 略.
class Solution2 {};

int main() { cout << Solution().fib(2) << '\n'; }