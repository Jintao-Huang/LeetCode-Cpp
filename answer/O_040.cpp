#include <leetcode>
#include <ml>
using namespace leetcode;

class Solution {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            return {};
        }
        if (k == 1) {
            return {*min_element(arr.begin(), arr.end())};
        }
        sort(arr.begin(), arr.end());
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
};

/// 小根堆法
class Solution2 {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            return {};
        }
        if (k == 1) {
            return {*min_element(arr.begin(), arr.end())};
        }
        int n = arr.size();
        if (k == n) {
            sort(arr.begin(), arr.end());
            return move(arr);
        }
        vector<int> res(k);
        make_heap(arr.begin(), arr.end(), greater<>());  // 小根堆
        for (int i = 0; i < k; ++i) {
            res[i] = arr[0];
            pop_heap(arr.begin(), arr.end(), greater<>());
            arr.pop_back();
        }
        return res;
    }
};

class Solution3 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            return {};
        }
        quick_select2(arr.begin(), arr.end(), k - 1);
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
};

/// faster. three_way_partition优化.
class Solution4 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            return {};
        }
        quick_select(arr.begin(), arr.end(), k - 1);
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
};

/// 大根堆法
/// TODO: 整理nsmallest, nlargest函数, _adjust_heap加入namespace leetcode;
class Solution5 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            return {};
        }
        if (k == 1) {
            return {*min_element(arr.begin(), arr.end())};
        }
        int n = arr.size();
        if (k == n) {
            sort(arr.begin(), arr.end());
            return move(arr);
        }
        //
        vector<int> res(arr.begin(), arr.begin() + k);
        make_heap(res.begin(), res.end());
        for (int i = k; i < n; ++i) {
            const int& x = arr[i];
            if (res[0] > x) {
                mini_stl::_adjust_heap(res.begin(), 0, k, x, less<>());
            }
        }
        return res;
    }
};

int main() {
    {
        vector<int> arr = {3, 2, 1};
        int k = 2;
        cout << Solution().getLeastNumbers(arr, k) << '\n';
    }
    {
        vector<int> arr = {3, 2, 1};
        int k = 2;
        cout << Solution2().getLeastNumbers(arr, k) << '\n';
    }
    {
        vector<int> arr = {3, 2, 1};
        int k = 2;
        cout << Solution3().getLeastNumbers(arr, k) << '\n';
    }
    {
        vector<int> arr = {3, 2, 1};
        int k = 2;
        cout << Solution4().getLeastNumbers(arr, k) << '\n';
    }
    {
        vector<int> arr = {3, 2, 1};
        int k = 2;
        cout << Solution5().getLeastNumbers(arr, k) << '\n';
    }
}