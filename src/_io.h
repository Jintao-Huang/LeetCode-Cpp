#ifndef _LEETCODE_IO_H
#define _LEETCODE_IO_H 1
#include <_types.h>

namespace leetcode {
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &nums) {
    // 支持matrix等.
    out << '[';
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        const T &x = nums[i];
        if (i > 0) {
            cout << ", ";
        }
        out << x;
    }
    out << ']';
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, const optional<T> &nums) {
    if (nums.has_value()) {
        out << nums.value();
    } else {
        out << "null";
    }
    return out;
}
#endif  // _LEETCODE_IO_H
}
