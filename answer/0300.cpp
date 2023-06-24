#include <leetcode>
using namespace leetcode;


/// faster
class Solution {
   public:
    inline int lengthOfLIS(vector<int>& nums) { return LIS(nums); }
};



/// 动态规划
class Solution2 {
   public:
    inline int lengthOfLIS(vector<int>& nums) { return LIS2(nums); }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(nums) << '\n';
    cout << Solution2().lengthOfLIS(nums) << '\n';
}