// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_DP_H
#define _ALG_DP_H 1
#include <_types.h>

namespace leetcode {
int LIS(const vector<int>& nums) {
    /// 最长递增子序列. Ot(nlogn)
    vector<int> st;
    for (const int& x : nums) {
        // 若要求最长单调非递减子序列, 则改成: `auto it = lower_bound(st.begin(), st.end(), x+1);`
        auto it = lower_bound(st.begin(), st.end(), x);
        if (it == st.end()) {
            st.push_back(x);
        } else {
            *it = x;
        }
    }
    return st.size();
}

int LIS2(const vector<int>& nums) {
    //- 遍历nums:i[0..n), j:[0..i), 如果nums[j]大于nums[i]. 则dp[j]=dp[i]+1
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

}  // namespace leetcode
#endif
