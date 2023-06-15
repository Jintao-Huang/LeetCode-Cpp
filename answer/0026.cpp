#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    cout << Solution().removeDuplicates(nums) << '\n';
}