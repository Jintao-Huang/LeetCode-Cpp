

#include <leetcode>
using namespace leetcode;

/// 使用hashmap(使用array替代)
class Solution {
   public:
    vector<int> intersection(vector<vector<int>>& nums) {
        array<int, 1005> arr = {};
        int n = nums.size();
        vector<int> res;
        if (!n) {
            return res;
        };
        //
        for (int i = 0; i < n - 1; ++i) {
            int m = nums[i].size();
            for (int j = 0; j < m; ++j) {
                int x = nums[i][j];
                ++arr[x];
            }
        }
        //
        int i = n - 1;
        int m = nums[i].size();
        for (int j = 0; j < m; ++j) {
            int x = nums[i][j];
            if (arr[x] == n - 1) {
                res.push_back(x);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


/// 使用hashmap
class Solution2 {
   public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> res;
        ::intersection(nums, res);
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<vector<int>> s = {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}};
    cout << Solution().intersection(s) << '\n';
    cout << Solution2().intersection(s) << '\n';
}