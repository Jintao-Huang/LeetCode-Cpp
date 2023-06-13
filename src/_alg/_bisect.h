#ifndef _ALG_BISECT_H
#define _ALG_BISECT_H 1

#include <_types.h>

namespace leetcode {

template <typename Tp>  // long long, int, RandomIterator
inline Tp get_mid(Tp lo, Tp hi) {
    /// [lo..hi], 选择偏lo. [1, 2]选择1
    /// [lo..hi), 选择偏hi. [1, 2]选择2
    return lo + ((hi - lo) >> 1);
}

template <typename RandomIterator, typename Tp>
RandomIterator binary_search_lc(RandomIterator first, RandomIterator last, Tp x) {
    RandomIterator _not_found = last;
    --last;
    while (first <= last) {
        RandomIterator mid = get_mid(first, last);
        if (*mid > x) {
            last = mid - 1;
        } else if (*mid < x) {
            first = mid + 1;
        } else {
            return mid;
        }
    }
    return _not_found;
}

template <typename Tp, typename Predicate>
Tp lower_bound_lc(Tp lo, Tp hi, Predicate pred) {
    /// 满足pred的最小idx. [lo..hi]是res范围
    while (lo < hi) {
        Tp mid = get_mid(lo, hi);
        if (pred(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

template <typename Tp, typename Predicate>  // Tp: int, RandomIterator
Tp upper_bound_lc(Tp lo, Tp hi, Predicate pred) {
    ///满足pred的最大idx. [lo..hi]是res范围
    while (lo < hi) {
        Tp mid = get_mid(lo, hi + 1);
        if (pred(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

template <typename RandomIterator, typename Tp>
inline RandomIterator _bisect_left(RandomIterator first, RandomIterator last, Tp x) {
    return lower_bound_lc(first, last, [x](RandomIterator mid) -> bool { return *mid >= x; });
}

template <typename RandomIterator, typename Tp>
inline RandomIterator _bisect_right(RandomIterator first, RandomIterator last, Tp x) {
    return lower_bound_lc(first, last, [x](RandomIterator mid) -> bool { return *mid > x; });
}

}  // namespace leetcode
#endif