#include <leetcode>

class Solution {
   public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        ///
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
            int s = numbers[lo] + numbers[hi];
            if (s < target) {
                ++lo;
            } else if (s > target) {
                --hi;
            } else {
                return {lo + 1, hi + 1};
            }
        }
        return {};
    }
};
/// TODO: 哈希表.
class Solution2 {};

int main() {
    vector<int> v = {2, 7, 11, 15};
    cout << Solution().twoSum(v, 9) << '\n';
}