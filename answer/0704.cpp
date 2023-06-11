#include <leetcode>
using namespace leetcode;
class Solution {
   public:
    inline int search(vector<int> &nums, int target) {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) {
            return -1;
        } else {
            return it - nums.begin();  // distance(nums.begin(), it);
        }
    }
};

class Solution2 {
   public:
    inline int search(vector<int> &nums, int target) { return binary_search_lc(nums, target); }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << Solution().search(nums, 9) << '\n';
    cout << Solution2().search(nums, 9) << '\n';
    return 0;
}