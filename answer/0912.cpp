
#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums.begin(), nums.end());
        return nums;
    }
};

class Solution2 {
   public:
    inline vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

/// TODO: 其他解法

int main() {
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        cout << Solution().sortArray(v) << '\n';
        cout << Solution2().sortArray(v) << '\n';
    }
}