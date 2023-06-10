#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        two_sum(nums, target, res);
        return res;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    cout << Solution().twoSum(nums, target) << '\n';
    return 0;
}