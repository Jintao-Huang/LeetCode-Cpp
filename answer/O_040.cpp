#include <leetcode>
using namespace leetcode;

#define _PARTIAL_CASE                                  \
    if (k == 0) {                                      \
        return {};                                     \
    }                                                  \
    if (k == 1) {                                      \
        return {*min_element(arr.begin(), arr.end())}; \
    }                                                  \
    int n = arr.size();                                \
    if (k == n) {                                      \
        return move(arr);                              \
    }

class Solution {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        _PARTIAL_CASE
        sort(arr.begin(), arr.end());
        arr.resize(k);
        return move(arr);
    }
};

/// 小根堆法
class Solution2 {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        _PARTIAL_CASE
        auto last = arr.end();
        make_heap(arr.begin(), last, greater<>());  // 小根堆
        for (int i = 0; i < k; ++i) {
            pop_heap(arr.begin(), last, greater<>());
            --last;
        }
        vector<int> res(arr.end() - k, arr.end());
        return res;
    }
};

class Solution3 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        _PARTIAL_CASE
        quick_select2(arr.begin(), arr.end(), k - 1);
        arr.resize(k);
        return move(arr);
    }
};

class Solution4 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        _PARTIAL_CASE
        // 使用three_way_partition.
        quick_select(arr.begin(), arr.end(), k - 1);
        arr.resize(k);
        return move(arr);
    }
};


/// 大根堆法
class Solution5 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        _PARTIAL_CASE
        heap_select_lc(arr.begin(), arr.begin() + k, arr.end());
        arr.resize(k);
        return move(arr);
    }
};

class Solution6 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        _PARTIAL_CASE
        partial_sort(arr.begin(), arr.begin() + k, arr.end());
        arr.resize(k);
        return move(arr);
    }
};

/// TODO: 写nth_element
class Solution7 {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        _PARTIAL_CASE
        nth_element(arr.begin(), arr.begin() + k, arr.end());
        arr.resize(k);
        return move(arr);
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
    {
        vector<int> arr = {3, 2, 1};
        int k = 2;
        cout << Solution6().getLeastNumbers(arr, k) << '\n';
    }
    {
        vector<int> arr = {3, 2, 1};
        int k = 2;
        cout << Solution7().getLeastNumbers(arr, k) << '\n';
    }
}