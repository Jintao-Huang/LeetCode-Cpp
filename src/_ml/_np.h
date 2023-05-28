#ifndef _ML_NP_H
#define _ML_NP_H 1
#include <_types.h>

namespace ml {

template <typename Tp>
Tp sum(const vector<Tp> &nums) {
    return accumulate(nums.begin(), nums.end(), static_cast<Tp>(0));
}

template <typename Tp>
double mean(const vector<Tp> &nums) {
    double res = sum(nums);
    return res / nums.size();
}

template <typename Tp>
Tp max(const vector<Tp> &nums) {
    return *max_element(nums.begin(), nums.end());
}

template <typename Tp>
Tp min(const vector<Tp> &nums) {
    return *min_element(nums.begin(), nums.end());
}

template <typename Tp>
double var(const vector<Tp> &nums) {
    // mean((x - mean) * (x - mean))
    double mean_ = mean(nums);
    double res = accumulate(nums.begin(), nums.end(), 0.,
                            [mean_](double x, Tp y) { return x + (y - mean_) * (y - mean_); });
    return res / nums.size();
}

template <typename Tp>
double std(const vector<Tp> &nums) {
    return sqrt(var(nums));
}

}  // namespace ml
#endif
