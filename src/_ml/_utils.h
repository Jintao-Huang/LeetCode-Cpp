#ifndef _ML_UTILS_H
#define _ML_UTILS_H 1
#include <_ml/_np.h>
#include <_types.h>

namespace ml {
int64_t default_timer() {
    chrono::time_point t = chrono::system_clock::now();
    return t.time_since_epoch().count();
}

// tuple<float, float, float, float, int> stat_array(const vector<int> &nums, string &stat_str_res) {
//     double mean = ml::mean(ts);
//     double std = ml::std(ts);
//     double max = ml::max(ts);
//     double min = ml::min(ts);
//     int len = nums.size();
//     stat_str_res.append(string("123"))
//     "%.6f±%.6f, min=%.6f, max=%.6f, len=%d\n", number, mean, std, max, min;
// }

// void test_time(function<void()> func, int number = 1, int warmup = 0,
//                function<int64_t()> timer = default_timer) {
//     vector<double> ts;
//     for (int _i = 0; _i < warmup; ++_i) {
//         func();
//     }
//     for (int _i = 0; _i < number; ++_i) {
//         int64_t t = timer();
//         func();
//         double t_d = (timer() - t) / 1e9;
//         ts.push_back(t_d);
//     }
//     // 求mean, std, max, min
//     double mean = ml::mean(ts);
//     double std = ml::std(ts);
//     double max = ml::max(ts);
//     double min = ml::min(ts);
// }

}  // namespace ml
#endif
