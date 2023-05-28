

#ifndef _LEETCODE_ALG_SEARCH
#define _LEETCODE_ALG_SEARCH 1

#include <_types.h>

namespace leetcode {

inline int get_mid(int lo, int hi) { return ((hi - lo) >> 1) + lo; }

int binary_search_lc(const vector<int> &nums, int x, int lo = 0, int hi = -1) {
    // res范围: [lo..hi)
    if (hi == -1) {
        hi = nums.size();
    }
    --hi;
    //
    while (lo <= hi) {
        int mid = get_mid(lo, hi);  // 避免int溢出
        if (nums[mid] > x) {
            hi = mid - 1;
        } else if (nums[mid] < x) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int lower_bound_lc(int lo, int hi, function<bool(int)> pred) {
    // pred: unary_predicate. [lo..hi]是res范围
    // 满足pred的最小idx.
    while (lo < hi) {
        int mid = get_mid(lo, hi);
        if (pred(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int upper_bound_lc(int lo, int hi, function<bool(int)> pred) {
    // 满足pred的最大idx. [lo..hi]是res范围
    while (lo < hi) {
        int mid = get_mid(lo, hi + 1);
        if (pred(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

inline int bisect_left(const vector<int> &nums, int x, int lo = 0, int hi = -1) {
    // [lo..hi]是res范围
    if (hi == -1) {
        hi = nums.size();
    }
    return lower_bound_lc(lo, hi, [&nums, x](int mid) { return nums[mid] >= x; });
}

inline int bisect_right(const vector<int> &nums, int x, int lo = 0, int hi = -1) {
    // [lo..hi]是res范围
    if (hi == -1) {
        hi = nums.size();
    }
    return lower_bound_lc(lo, hi, [&nums, x](int mid) { return nums[mid] > x; });
}

}  // namespace leetcode
#endif