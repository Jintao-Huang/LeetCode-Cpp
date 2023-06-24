// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_DP_H
#define _ALG_DP_H 1
#include <_types.h>

namespace leetcode {
int LIS(vector<int>& nums) {
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
}  // namespace leetcode
#endif
