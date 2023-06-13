#include <leetcode>
using namespace leetcode;


class Solution {
   public:
    int climbStairs(int n) { return fib(++n); }
};

/// 通项公式法(组合数学), 略.
class Solution2 {};

int main() { cout << Solution().climbStairs(2) << '\n'; }