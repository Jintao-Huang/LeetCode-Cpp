#ifndef _ML_UTILS_H
#define _ML_UTILS_H 1
#include <_ml/_np.h>
#include <_types.h>

namespace ml {
inline int64_t default_timer() {
    chrono::time_point t = chrono::system_clock::now();
    return t.time_since_epoch().count();
}

struct StatData {
    double mean, std, min, max;
    int len;
    StatData(double mean, double std, double min, double max, int len)
        : mean(mean), std(std), min(min), max(max), len(len) {}

    friend ostream& operator<<(ostream& out, StatData stat_data) {
        out << setprecision(6) << fixed;
        out << stat_data.mean << "±" << stat_data.std;
        out << ", min=" << stat_data.min << ", max=" << stat_data.max << ", len=" << stat_data.len;
        // recover
        return out << defaultfloat;
    }
};

template < typename Tp>
inline StatData stat_array(const vector<Tp>& nums) {
    double mean = ml::mean(nums);
    double std = ml::std(nums);
    double min = ml::min(nums);
    double max = ml::max(nums);
    int len = nums.size();
    return StatData(mean, std, min, max, len);
}

void test_time(function<void()> func, int number = 1, int warmup = 0,
               function<int64_t()> timer = default_timer) {
    vector<double> ts;
    for (int _i = 0; _i < warmup; ++_i) {
        func();
    }
    for (int _i = 0; _i < number; ++_i) {
        int64_t t = timer();
        func();
        double t_d = (timer() - t) / 1e9;
        ts.push_back(t_d);
    }
    StatData st = stat_array(ts);
    cout << "time[number=" << number  << "]: ";
    cout << st << '\n';
}

}  // namespace ml
#endif
