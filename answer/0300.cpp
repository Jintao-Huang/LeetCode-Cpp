#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline int lengthOfLIS(vector<int>& nums) { return LIS(nums); }
};

/// TODO: 使用动态规划
class Solution2 {};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(nums) << '\n';
}