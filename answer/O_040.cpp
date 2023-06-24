#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
};

class Solution2 {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        make_heap(arr.begin(), arr.end(), greater<>());  // 小根堆
        vector<int> res(k);
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
        random_select2(arr.begin(), arr.end(), k - 1);
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
        random_select(arr.begin(), arr.end(), k - 1);
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
};

int main() {
    // {
    //     vector<int> arr = {3, 2, 1};
    //     int k = 2;
    //     cout << Solution().getLeastNumbers(arr, k) << '\n';
    //     cout << Solution2().getLeastNumbers(arr, k) << '\n';
    // }
    // {
    //     vector<int> arr = {3, 2, 1};
    //     int k = 2;
    //     cout << Solution3().getLeastNumbers(arr, k) << '\n';
    // }
    // {
    //     vector<int> arr = {3, 2, 1};
    //     int k = 2;
    //     cout << Solution4().getLeastNumbers(arr, k) << '\n';
    // }
    vector<int> arr = {0, 0, 0, 1, 2, 2, 3, 7, 6, 1};
    cout << Solution4().getLeastNumbers(arr, 3) << '\n';
}