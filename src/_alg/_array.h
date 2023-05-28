#ifndef _LEETCODE_ALG_ARRAY_H
#define _LEETCODE_ALG_ARRAY_H 1

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

template <typename T>
void _partial_sum_lc(const vector<T>& nums, vector<T>& res, optional<T> init_val = nullopt,
                     function<T(T, T)> binary_op = plus<>()) {
    int n = nums.size();
    typename vector<T>::const_iterator it = nums.cbegin();
    if (!init_val.has_value()) {
        if (n == 0) {
            return;
        }
        init_val = *(it++);
    }
    res.push_back(init_val.value());
    for (; it != nums.end(); ++it) {
        res.push_back(binary_op(res.back(), *it));
    }
}

template <typename Tp>
void partial_sum_lc(const vector<Tp>& nums, vector<Tp>& res) {
    return _partial_sum_lc<Tp>(nums, res);
}
template <typename Tp>
void partial_sum_lc(const vector<Tp>& nums, vector<Tp>& res, Tp init_val) {
    return _partial_sum_lc<Tp>(nums, res, init_val);
}
template <typename Tp, typename BinaryOperation>
void partial_sum_lc(const vector<Tp>& nums, vector<Tp>& res, Tp init_val,
                    BinaryOperation binary_op) {
    return _partial_sum_lc<Tp>(nums, res, init_val, binary_op);
}

}  // namespace leetcode

#endif