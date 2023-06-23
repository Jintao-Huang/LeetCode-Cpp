
#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline vector<int> sortArray(vector<int>& nums) {
        vector<int> res = move(nums);
        quick_sort(res.begin(), res.end());
        return res;
    }
};

class Solution2 {
   public:
    inline vector<int> sortArray(vector<int>& nums) {
        vector<int> res = move(nums);
        sort(res.begin(), res.end());
        return res;
    }
};

class Solution3 {
   public:
    inline vector<int> sortArray(vector<int>& nums) {
        vector<int> res = move(nums);
        merge_sort(res.begin(), res.end());
        return res;
    }
};

class Solution4 {
   public:
    inline vector<int> sortArray(vector<int>& nums) {
        vector<int> res = move(nums);
        heap_sort(res.begin(), res.end());
        return res;
    }
};

/// faster
class Solution5 {
   public:
    inline vector<int> sortArray(vector<int>& nums) {
        vector<int> res = move(nums);
        int min_ = *min_element(res.begin(), res.end());
        int max_ = *max_element(res.begin(), res.end());
        count_sort(res.begin(), res.end(), min_, max_);
        return res;
    }
};

int main() {
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        cout << Solution().sortArray(v) << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        cout << Solution2().sortArray(v) << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        cout << Solution3().sortArray(v) << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        cout << Solution4().sortArray(v) << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 7, 6};
        cout << Solution4().sortArray(v) << '\n';
    }
}