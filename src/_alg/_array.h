#ifndef _ALG_ARRAY_H
#define _ALG_ARRAY_H 1

#include <_types.h>

namespace leetcode {
template <typename Tp>
inline double euclidean_dist(Tp x, Tp y, Tp x2, Tp y2, bool square = false) {
    Tp d = x2 - x, d2 = y2 - y;
    double res = d * d + d2 * d2;
    if (square) {
        return res;
    }
    res = sqrt(res);
    return res;
}

template <typename Tp>
inline int manhattan_dist(Tp x, Tp y, Tp x2, Tp y2) {
    Tp d = x2 - x, d2 = y2 - y;
    return abs(d) + abs(d2);
}

template <typename Tp, typename BinaryOperation = plus<Tp>>
void partial_sum_lc(const vector<Tp>& nums, vector<Tp>& res,
                     BinaryOperation binary_op = BinaryOperation()) {
    typename vector<Tp>::const_iterator first = nums.begin(), last = nums.end();
    if (first == last){
        return;
    }
    if (res.empty()){
        res.push_back(*first++);
    }
    while(first != last) {
        res.push_back(binary_op(res.back(), *first++));
    }
}
}  // namespace leetcode

#endif