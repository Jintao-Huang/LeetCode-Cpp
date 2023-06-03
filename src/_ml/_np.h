#ifndef _ML_NP_H
#define _ML_NP_H 1
#include <_types.h>

namespace ml {

template <typename Sequence>
inline typename Sequence::value_type sum(const Sequence &nums) {
    return accumulate(nums.begin(), nums.end(), static_cast<typename Sequence::value_type>(0));
}

template <typename Sequence>
inline double mean(const Sequence &nums) {
    double res = static_cast<double>(ml::sum(nums));
    return res / nums.size();
}

template <typename Sequence>
inline typename Sequence::value_type max(const Sequence &nums) {
    return *max_element(nums.begin(), nums.end());
}

template <typename Sequence>
inline typename Sequence::value_type min(const Sequence &nums) {
    return *min_element(nums.begin(), nums.end());
}

template <typename Sequence>
inline double var(const Sequence &nums) {
    // mean((x - mean) * (x - mean))
    typedef typename Sequence::value_type Tp;
    double mean_ = ml::mean(nums);
    function<double(double, Tp)> binary_op = [mean_](double x, Tp y) -> double {
        return x + (y - mean_) * (y - mean_);
    };
    double res = accumulate(nums.begin(), nums.end(), 0., binary_op);
    return res / nums.size();
}

template <typename Sequence>
inline double std(const Sequence &nums) {
    return sqrt(ml::var(nums));
}

}  // namespace ml
#endif
